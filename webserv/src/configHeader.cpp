#include <Config.hpp>

std::string Config::extractFilenameFromHeader(const std::string& header)
{
	std::string filename;
	size_t filenamePos = header.find("filename=");

	if (filenamePos != std::string::npos)
	 {
		size_t filenameStart = filenamePos + 10;
		size_t filenameEnd = header.find("\"", filenameStart);
		if (filenameEnd != std::string::npos)
			filename = header.substr(filenameStart, filenameEnd - filenameStart);
	}
	return filename;
}

std::string Config::extractBoundaryFromHeader(const std::string& header)
{
	size_t boundaryPos = header.find("boundary=");
	std::string boundary;

	if (boundaryPos != std::string::npos)
	{
		size_t boundaryStart = boundaryPos + 9;
		size_t boundaryEnd = header.find("\r\n", boundaryStart);
		boundary = header.substr(boundaryStart, boundaryEnd - boundaryStart);
	}
	return("--"+boundary+"--");
}

std::string Config::extractConnectionFromHeader(const std::string &header)
{
	size_t connectionPos = header.find("Connection: ");
	std::string connection;

	if (connectionPos != std::string::npos)
	{
		size_t connectionStart = connectionPos + 12;
		size_t connectionEnd = header.find("\r\n", connectionStart);
		connection = header.substr(connectionStart, connectionEnd - connectionStart);
	}
	return(connection);
}

std::string Config::extractHostFromHeader(const std::string &header)
{
	size_t connectionPos = header.find("Host: ");
	std::string host;

	if (connectionPos != std::string::npos)
	{
		size_t connectionStart = connectionPos + 6;
		size_t connectionEnd = header.find("\r\n", connectionStart);
		host = header.substr(connectionStart, connectionEnd - connectionStart);
	}
	return(host);
}

std::string Config::removeHeaderChunk(const std::string& requestData) 
{
	size_t positions = 0;
	size_t pos = 0;
	std::string separator = "\r\n\r\n";
	std::string result;

	if ((pos = requestData.find(separator, pos)) != std::string::npos) 
	{
		positions = pos;
		pos += separator.length();
	}
	
	result = requestData.substr(positions + separator.size() + 3);
	return (result.substr(0, result.length() - 7));
}

std::string Config::removeHeader(const std::string& requestData) 
{
	size_t positions;
	size_t pos = 0;
	std::string separator = "\r\n\r\n";
	int tmp;
	   
	while ((pos = requestData.find(separator, pos)) != std::string::npos) 
	{
		positions = pos;
		pos += separator.length();
	}
	pos = 0;
	tmp = positions + 4;
	positions = 0;
	separator = extractBoundaryFromHeader(requestData);
   
	if ((pos = requestData.substr(tmp).find(extractBoundaryFromHeader(separator), pos)) != std::string::npos)
	{
		positions = pos;
		pos += separator.length();
	}
	return (requestData.substr(tmp, positions));
}

int Config::contentHeader(const std::string &imageData)
{
		std::string line;
		int contentLength;
		std::istringstream iss(imageData);
		
		contentLength = 0;
		while (std::getline(iss, line)) 
        {
			if (line.substr(0, 14) == "Content-Length") 
			{
				contentLength = std::stoi(line.substr(16));
				break;
			}
        }
	return (contentLength);
}

const char* Config::removeHeaderCgi(const char* requestData) 
{
    const char* separator = "\r\n\r\n";
    const char* pos = strstr(requestData, separator);

	if (pos != nullptr) 
	{
        pos += strlen(separator);
        return pos;
    }
    return requestData;
}

bool 	Config::valid_cgi_filename(Location *location, std::string filename, std::string method)
{
	if (method == "GET")
	{
		size_t query_pos = filename.find('?');
		if (query_pos != std::string::npos) 
        	filename = filename.substr(0, query_pos);
	} 
	filename = filename.substr(filename.find_last_of("/") + 1);
	return (location->get_cgi_ext_value(filename.substr(filename.find_last_of(".") + 1)));
}
