#include <Config.hpp>

bool Config::isDirectory(const std::string& path) 
{
    struct stat fileInfo;
    if (stat(path.c_str(), &fileInfo) != 0) 
        return false;
    return S_ISDIR(fileInfo.st_mode);
}

std::string Config::autoIndex(std::string path)
{
    std::stringstream body;
    body << "<html><body><h1>Index of " << path << "</h1><ul>";

    DIR* dir = opendir(path.c_str());

    if (dir) 
    {
        struct dirent* entry;
        std::vector<std::string> parts; // Usar para eliminar duplicados
        std::string cleanedPath = path; // Usar para construir la ruta limpia

        while ((entry = readdir(dir)) != NULL)
        { 
            if (entry->d_type == DT_DIR) 
            {
                std::string subPath = cleanedPath.substr(1) + "/" + entry->d_name;

                // Eliminar duplicados de la ruta
                if (std::find(parts.begin(), parts.end(), subPath) == parts.end()) 
                {
                    parts.push_back(subPath);
                    body << "<li><a href=\"" << subPath << "/\">" << entry->d_name << "/</a></li>";
                }
            } 
            else if (entry->d_type == DT_REG) 
            {
                // Mantener la ruta para archivos regulares
                std::string filePath = cleanedPath.substr(1) + "/" + entry->d_name;
                body << "<li><a href=\"" << filePath << "\">" << entry->d_name << "</a></li>";
            }
        }
        closedir(dir);
    }

    path.clear();
    body << "</ul></body></html>";
    return body.str();
}


ssize_t Config::initUser(std::string path, std::string method, std::string data, const int client_fd)
{
    std::string response, cookies;
    StatusCode statusCode;
    std::string responseBody;
	std::string connection = "keep-alive";
	ssize_t		 bytesSent;

    cookies = loginCall(path, method, statusCode, data, responseBody);
	if (!(statusCode == OK || statusCode == Found))
	 	bytesSent = sendResponse(statusCode, "text/html", PageErrorCode(statusCode), client_fd, connection, method, "", cookies);
	else
    	bytesSent = sendResponse(statusCode, "text/html", responseBody, client_fd, connection, method, "", cookies);
    return bytesSent;
}

std::string Config::extractInitialDirectory(const std::string& path) 
{
    size_t firstSlash = path.find_first_of('/');
    if (firstSlash != std::string::npos) {
        size_t secondSlash = path.find_first_of('/', firstSlash + 1);
        if (secondSlash != std::string::npos) {
            return path.substr(0, secondSlash);
        } else {
            return path;
        }
    }
    return path;
}

bool Config::hasFilenameExtension(const std::string& path) 
{
    size_t lastDot = path.find_last_of('.');
    size_t lastSlash = path.find_last_of('/');
    return lastDot != std::string::npos && (lastSlash == std::string::npos || lastDot > lastSlash);
}

bool Config::minimumFile() 
{
	if (server_name.length() == 0)
		return false;
	for (std::vector<Location *>::size_type i = 0; i < location.size(); ++i)
		if (location[i]->get_path() == "{")
			return false;
	if (host_name.empty())
		return false;
	if (ports.empty())
		return false;
	return true;
}

std::vector<std::pair<std::string, std::string> > Config::initRoutes(std::string  path) 
{
	std::vector<std::pair<std::string, std::string> > contentTypes;
	std::string entry_name;
	dirent* 	entry;

	
	if (isDirectory("." + path) && path != "/")
	{
		DIR  	*dir_stream = opendir(("." + path).c_str());
		entry = readdir(dir_stream);
		while (entry != NULL)
		{
			entry_name = entry->d_name;
    	    if (entry_name != "." && entry_name != "..")
			{
    	        std::string full_path = path + "/" + entry_name;
				contentTypes.push_back(std::make_pair(full_path,  setTypeRoute(entry_name.substr(entry_name.find('.') + 1))));
    	    }
			entry = readdir(dir_stream);
    	}
		closedir(dir_stream);
	}
	else if (fileExists("."+path) || path == "/")
	{
		contentTypes.push_back(std::make_pair(path,  setTypeRoute(path.substr(path.find('.') + 1))));
	}
	return contentTypes;
}

std::string Config::setTypeRoute(std::string extension)
{
	
	std::map<std::string, std::string> mimeTypes;
	
	mimeTypes.insert(std::make_pair("html", "text/html"));
	mimeTypes.insert(std::make_pair("/", "text/html"));
    mimeTypes.insert(std::make_pair("css", "text/css"));
    mimeTypes.insert(std::make_pair("js", "application/javascript"));
    mimeTypes.insert(std::make_pair("jpg", "image/jpeg"));
    mimeTypes.insert(std::make_pair("jpeg", "image/jpeg"));
    mimeTypes.insert(std::make_pair("png", "image/png"));
    mimeTypes.insert(std::make_pair("gif", "image/gif"));
    mimeTypes.insert(std::make_pair("bmp", "image/bmp"));
    mimeTypes.insert(std::make_pair("ico", "image/x-icon"));
    mimeTypes.insert(std::make_pair("svg", "image/svg+xml"));
    mimeTypes.insert(std::make_pair("mp4", "video/mp4"));
	mimeTypes.insert(std::make_pair("/", "text/html"));
    mimeTypes.insert(std::make_pair("webm", "video/webm"));
    mimeTypes.insert(std::make_pair("txt", "text/plain"));
    mimeTypes.insert(std::make_pair("pdf", "application/pdf"));
	
	if (mimeTypes.count(extension))
        return mimeTypes[extension];
    return "application/octet-stream";
}

bool Config::fileExists(const std::string& path) 
{
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}

bool Config::file_exist(std::string file_name)
{
	std::ifstream file; 
   	file.open(file_name);
   	if(file) 
	{
		file.close();
		return true;
	}
	file.close();
   	return false;
}

std::string Config::PageErrorCode(StatusCode statusCode)
{
	std::string responseBody;

	// Cargar el contenido del archivo HTML de error 404
	HttpResponse response;
	std::ifstream errorFile1(get_error_page(statusCode)); 
	std::ifstream errorFile(get_error_page(statusCode).substr(1)); 
	if (errorFile)
	{
		std::ostringstream errorContent;
		errorContent << errorFile.rdbuf();
		errorFile.close();

		responseBody = errorContent.str();
	}
	else if (errorFile1)
	{
		std::ostringstream errorContent;
		errorContent << errorFile1.rdbuf();
		errorFile1.close();

		responseBody = errorContent.str();
	} 
	else 
		responseBody = "<h1>" + response.getStatusHeader(statusCode) + " </h1>";

	return (responseBody);
}

std::string Config::toChar(int n)
{
    std::stringstream ss;
    ss << n;
    return ss.str();
}

void Config::init_host_name()
{
	size_t start;
	size_t end;
	std::string line;
	std::string param;
	std::string my_hostname;

 
	start = 0;
	param = "host_name";
	end = this->file.find(';') + 1;
	while (file.find(";", start) != std::string::npos)
	{
		line =  file.substr(start, end - start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		if (param == line.substr(0, param.length()))
		{
				my_hostname = line.substr(param.length() + 1, line.length() - param.length() - 2);
				host_name.push_back(my_hostname);
		}
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}
}
bool number_of_brace(std::string file_name)
{
	int count_open;
	int count_close;

	count_open = 0;
	count_close = 0;

  	for (size_t i = 0; i < file_name.size(); i++)
		if (file_name[i] == '{')
			count_open++;
	for (size_t i = 0; i < file_name.size(); i++)
		if (file_name[i] == '}') 
			count_close++;
	if (count_close == count_open)
  		return true;
	std::cerr << "Error: file with bad format, open scopes" << std::endl;
	return false;
}

int	number_of_section(std::string my_file, std::string param)
{
	int 	count = 0;
	bool 	insideServerSection = false;
	size_t 	pos = 0;
	size_t	pos_rel = 0;

	pos = my_file.find(param);

	while (pos_rel < my_file.size() && pos < my_file.size()) {
		  
		if (!insideServerSection) 
		{
			size_t openingBracePos = my_file.find("{", pos + param.length());
			if (openingBracePos != std::string::npos && openingBracePos < pos + param.size() + 5) 
			{
				insideServerSection = true;
				count++;
			}
		} 
		else 
		{
			size_t closingBracePos = my_file.find("}", pos + param.length());
			if (closingBracePos != std::string::npos) 
				insideServerSection = false;
		}

		pos_rel = pos + param.size();
		pos = my_file.find(param, pos_rel + 1);
	}

	if (number_of_section_bracket(my_file) > count)
		count = 0;
	return count;
} 

//función que comprueba el numero de bloques de servidores que tenemos pero lo comprueba por brackets, no por nombre con server
int	number_of_section_bracket(std::string my_file) {

	size_t	pos_open = 0;
	size_t	pos_close = 0;
	size_t	pos_rel = 0;
	size_t	num_bra = 0;
	size_t	num_sec = 0;

	while (pos_open < my_file.size() || pos_close < my_file.size()) {

		pos_open = my_file.find("{", pos_rel);
		pos_close = my_file.find("}", pos_rel);
		if (pos_open < pos_close && pos_open < my_file.size()) {
			pos_rel = pos_open + 1;
			++num_bra;
		}
		else if (pos_open > pos_close && pos_close < my_file.size()) {
			pos_rel = pos_close + 1;
			--num_bra;
		}
		if (num_bra == 0 && (pos_open < my_file.size() || pos_close < my_file.size()))
			++num_sec;
	}

	return num_sec;
}
