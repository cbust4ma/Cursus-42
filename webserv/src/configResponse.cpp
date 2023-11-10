#include <Config.hpp>
#include <string>

ssize_t Config::sendAll(int socket, const char* buffer, size_t length) 
{
	size_t totalSent = 0;
	while (totalSent < length) {
		ssize_t bytesSent = send(socket, buffer + totalSent, length - totalSent, 0);
		if (bytesSent == -1)
			return -1;
		totalSent += bytesSent;
	}
	return totalSent;
}


ssize_t Config::sendResponse(StatusCode statusCode, std::string contentType,
	std::string responseBody, int client_fd, std::string connection, std::string method, std::string msg, std::string cookies)
{
	
	int 			bytesSent;
	HttpResponse 	response;
	response.setStatus(statusCode);
	response.setResponseHeaders(contentType, responseBody,connection, method, msg, cookies);
	response.setBody(responseBody);
	std::string responseString = response.getResponse();
	bytesSent = sendAll(client_fd, responseString.c_str(), responseString.size());
	return (bytesSent);
}

std::string handleFile(StatusCode &statusCode, std::string &path) 
{
    std::ifstream route("."+path);
    if (route)
    {
        std::ostringstream routeContent;
        routeContent << route.rdbuf();
        route.close();
        statusCode = OK;
        return routeContent.str();
    }
    else
      statusCode = NotFound;
    return "<h1>Not Found</h1>";
}

ssize_t Config::getData(std::string &data, int client_fd, Location *my_location, std::string &path, StatusCode &statusCode)
{
		HttpResponse 										response;
		std::string 										contentType;
		std::string 										responseBody;
		std::string 										connection;
		std::vector<std::pair<std::string, std::string> >   contentTypes;
		int											bytesSent;



		if ((my_location != NULL && my_location->get_path() != "/default/"))
			contentTypes = initRoutes(path);
		if (my_location->get_redirect().length() > 8)
			return  sendResponse(MovedPermanently, "", "", client_fd,extractConnectionFromHeader(data), "redirect", my_location->get_redirect(), "");
		if (my_location->get_autoindex()  && isDirectory("."+path))
			responseBody = autoIndex("."+path);
		else if (path == "/" || path == my_location->get_path())
		{
				std::ifstream rootFile("."+my_location->get_path() + "/"+ my_location->get_index());
				if (rootFile) 
				{
					std::ostringstream rootContent;
					rootContent << rootFile.rdbuf();
					rootFile.close();

					contentType = "text/html";
					responseBody = rootContent.str();
					connection = extractConnectionFromHeader(data);
					
				}
				else
				{
					statusCode = NotFound;
					responseBody = PageErrorCode(NotFound);

				}
				
		}
		else 
		{
			bool routeFound = false;
			for (size_t i = 0; i < contentTypes.size(); ++i) 
			{
				if (contentTypes[i].first == path) 
				{
					routeFound = true;
					contentType = contentTypes[i].second;
					std::string filePath = path.substr(1);
					std::ifstream file(filePath.c_str(), std::ios::binary);
					if (file) 
					{
						std::ostringstream content;
						content << file.rdbuf();
						file.close();
						responseBody = content.str();
						statusCode = OK;
					} 
					else 
					{
						routeFound = false; // El archivo no existe
						break; // Salir del bucle si el archivo no existe
					}
				}
			}
			if (!routeFound) 
			{
				statusCode = NotFound;
				responseBody = PageErrorCode(statusCode);
			}
		}
		connection = extractConnectionFromHeader(data);
		bytesSent = sendResponse(statusCode, contentType, responseBody, client_fd, connection, "", "", "");
		return (bytesSent);
}


ssize_t Config::server_data(const int client_fd, std::string data) 
{
	ssize_t 											bytesSent = 0;

	std::istringstream                                  iss(data);
	std::string                                         HttpClient;
	Location                                            *my_location;


	
	getline(iss, HttpClient);
	std::string method, path, protocolVersion;
	std::istringstream requestStream(HttpClient);
	requestStream >> method >> path >> protocolVersion;
	
	if (get_host_name(extractHostFromHeader(data)) == false)
		return sendResponse(NotFound, "text/html", PageErrorCode(NotFound), client_fd, extractConnectionFromHeader(data), "", "", "");

	if (path[path.size() - 1] == '/'  && path.length() != 1)
			path = path.substr(0, path.size() - 1);
	my_location = get_location(extractInitialDirectory(path));
	StatusCode statusCode = OK;
	printSeparator("Request type " + method + " requested resource " + path + " " + extractInitialDirectory(path) + " location root " /* + my_location->get_path()*/);
	if (path == "/login" || path == "/dologout")
		bytesSent =  initUser(path, method, data, client_fd);
	if (my_location == NULL)
	{
		my_location = get_location("/default/");
		if (my_location == NULL)
			my_location = get_location("/");
	}
	if (method == "GET" && my_location->get_get() && valid_cgi_filename(my_location, path, "GET"))
		bytesSent =  this->httpGetCgi(data, client_fd, "." + path);
	else if (method == "GET" && my_location->get_get()) // ver si el metodo es allowed method en su path(location) correspondiente
		bytesSent =  getData(data, client_fd, my_location, path, statusCode);
	else if (method == "POST" && my_location->get_post() && valid_cgi_filename(my_location, path, "POST"))
		bytesSent =  this->httpPostCgi(data, client_fd, "." + path);
	else if ((method == "POST" && my_location->get_post()) || data.find("Transfer-Encoding: chunked") != std::string::npos)
		bytesSent =  this->httpPost(data, client_fd, my_location);
	else if (method == "DELETE" && my_location->get_delete())
		bytesSent = httpDelete(data, client_fd, path.substr(path.find_last_of("/")+1), my_location);
	else if ((method != "POST" && my_location->get_post()) ||
		(method != "GET" && my_location->get_get()) || (method != "DELETE" && my_location->get_delete()))
		bytesSent = sendResponse(MethodNotAllowed, "text/html", PageErrorCode(MethodNotAllowed), client_fd,extractConnectionFromHeader(data), "NOTALLOW", sendNotAllowedMsg(my_location), "");
	else
		bytesSent = sendResponse(MethodNotAllowed, "text/html", PageErrorCode(MethodNotAllowed), client_fd,extractConnectionFromHeader(data), "NOTALLOW", sendNotAllowedMsg(my_location), "");
	data.clear();
	return bytesSent;
}

std::string	Config::sendNotAllowedMsg(Location *my_location)
{
	std::string answ;
	if (my_location == NULL)
		return ("GET, POST, DELETE");
	if (my_location->get_get())
		answ += "GET ";
	if (my_location->get_post())
		answ += "POST ";
	if (my_location->get_delete())
		answ += "DELETE";
	return (answ);
}
