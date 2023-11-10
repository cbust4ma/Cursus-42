#include <Config.hpp>

int Config::saveImageDataToFile(const std::string& imageData, const std::string& filename, Location *location) 
{
	std::fstream 		file;
	std::string 		downald_path;
	DIR 				*dir;

	downald_path = "." + location->get_path() + "/upload/";
	if (location->get_upload().length() != 0)
		downald_path = "." + location->get_path() + location->get_upload();
	if ((dir = opendir(downald_path.c_str())) == nullptr)
		mkdir(downald_path.c_str(), 0777);
	else
		closedir(dir);
	file.open(downald_path + "/" + filename, std::ios::out | std::ios::binary);

	if (!file.is_open())
		return (1);
	if (file.is_open()) 
	{
			file.write(imageData.data(), imageData.size());
			file.close();
	} 
	else 
		return (1);
	return (0);
}



int Config::httpDelete (std::string header, int client_fd, std::string filename, Location *location)
{
    int bytesSent = 0;
    StatusCode statusCode;

    std::string filePath;
	filePath =  "." + location->get_path() + "/upload";
	if (location->get_upload().length() != 0)
		filePath = "." + location->get_path() + location->get_upload();	
	filePath = filePath + "/" + filename;
    int statusDelete = std::remove(filePath.c_str());
    std::string responseBody = "<h1> erase file " + filename + "  </h1>"; 
    if ( statusDelete == 0)
        statusCode = OK;
    
    else
        statusCode = NotFound;

    bytesSent = sendResponse(statusCode, "text/html", responseBody, client_fd,extractConnectionFromHeader(header), "" ,"", "");
    return (bytesSent);

}

int Config::httpPost(const std::string& requestData, int client_fd, Location *location) 
{
	int 			bytesSent = 0;
	StatusCode 		statusCode;
	std::string 	imageData;
	int				size;

	std::string responseBody = "<h1>Enviado </h1>";

	if (requestData.find("Transfer-Encoding: chunked") != std::string::npos)
		imageData = removeHeaderChunk(requestData);
	
	else
		imageData = removeHeader(requestData);
	
	std::string filename = extractFilenameFromHeader(requestData);
	if (imageData.size() > get_body_size()) 
	{
		statusCode = RequestEntityTooLarge;
		responseBody = "<h1>La imagen es demasiado grande. El size maximo permitido es de " + std::to_string(get_body_size()) + "MB y es de " +  std::to_string(imageData.size()) + " .</h1>";
	}
	else if (!imageData.empty() && filename.find(" ") == std::string::npos) 
	{
		size = saveImageDataToFile(imageData, filename, location);
		if ( size == 0)
		{
			statusCode = OK;
			responseBody = "<h1>Enviado </h1>";
			filename.clear();
		}
		else 
		{
			statusCode = InternalServerError;
			responseBody = "<h1>Error al guardar la imagen</h1>";
		}
	} 
	else 
	{
		statusCode = BadRequest;
		responseBody = "<h1>Solicitud incorrecta</h1>";
	}
	filename.clear();
	bytesSent = sendResponse(statusCode, "text/html", PageErrorCode(statusCode), client_fd, extractConnectionFromHeader(requestData),"", "", "");

	return (bytesSent);
}
