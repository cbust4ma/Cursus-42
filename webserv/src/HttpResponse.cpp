#include "HttpResponse.hpp"
#include <sys/_types/_time_t.h>
#include <vector>
#include <chrono>
#include <iomanip>

HttpResponse::HttpResponse() 
{
	status = OK;
	statusHeaders[OK] = "200 OK"; //no
	statusHeaders[NoContent] = "204 No Content";
	statusHeaders[MovedPermanently] = "301 Moved Permanently"; //no
	statusHeaders[BadRequest] = "400 Bad Request";
	statusHeaders[NotFound] = "404 Not Found";
	statusHeaders[MethodNotAllowed] = "405 Method Not Allowed";
	statusHeaders[RequestEntityTooLarge] = "413 Request Entity Too Large";
	statusHeaders[Unauthorized] = "401 Unauthorized";
	statusHeaders[Found] = "302 Found"; // no
	statusHeaders[GatewayTimeout] = "504 Gateway Timeout";
	statusHeaders[InternalServerError] = "500 Internal Server Error";

}
HttpResponse::~HttpResponse(){}

HttpResponse::HttpResponse(const HttpResponse& other) 
{
	if (this != &other) 
	{
		headers = other.headers;
		bodyStream.str(other.bodyStream.str());
		statusHeaders = other.statusHeaders;
		status = other.status;
	}
}

// Sobrecarga del operador de asignación
HttpResponse& HttpResponse::operator=(const HttpResponse& other) 
{
    if (this != &other) {
        headers = other.headers;
        bodyStream.str(other.bodyStream.str());
        statusHeaders = other.statusHeaders;
        status = other.status;
    }
    return *this;
}

void HttpResponse::setHeader(const std::string &key, const std::string &value)
{
	headers[key] = value;
}

void HttpResponse::setBody(const std::string &body)
{
	bodyStream << body;
}

std::string HttpResponse::getStatusHeader(StatusCode statusCode) const
{
	
	std::map<StatusCode, std::string>::const_iterator it = statusHeaders.find(statusCode);
	if (it != statusHeaders.end())
	{
		return "HTTP/1.1 " + it->second;
	}
	return "";
}

std::string HttpResponse::getResponse() const
{
	std::stringstream response;
	std::map<std::string, std::string>::const_iterator it;

	response << getStatusHeader(status) << "\r\n";
	for (it = headers.begin(); it != headers.end(); ++it)
		response << it->first << ": " << it->second << "\r\n";
	response << "\r\n";
	response << bodyStream.str();

	return response.str();

}

std::string expireCookies()
{
    const int sessionDurationInSeconds = 9000; // Duración de la sesión en segundos
    time_t currentTime = time(nullptr);
    time_t expirationTime = currentTime + sessionDurationInSeconds;
    struct tm* localTimeInfo = localtime(&expirationTime);
    char buffer[128];
    strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H:%M:%S GMT", localTimeInfo);

    return std::string(buffer);
}


void HttpResponse::setResponseHeaders(const std::string& contentType, const std::string& responseBody,
	const std::string& connection, const std::string& method, std::string msg, std::string cookies)
{
	if (method == "NOTALLOW")
		setHeader("Allow", msg);
	if (method == "redirect")
		setHeader("Location", msg);
	if (method != "redirect")
		setHeader("Content-Type", contentType);
	setHeader("Content-Length", std::to_string(responseBody.size()));
	setHeader("Connection: ", connection);
	// Cabeceras para evitar el almacenamiento en caché
	setHeader("Cache-Control", "no-store, no-cache, must-revalidate, max-age=0");
	setHeader("Pragma", "no-cache");
	setHeader("Expires", "0");
	if (cookies == "deletecookie")
		setHeader("Set-Cookie", "session="+cookies+"; HttpOnly; expires= Fri, 01 Sep 2021 07:44:31 GMT");
	else if (!cookies.empty())
		setHeader("Set-Cookie", "session="+cookies+"; HttpOnly; expires= "+ expireCookies());
	if (method == "loggin")
		setHeader("Location", "/login");
	
}

void HttpResponse::setStatus(StatusCode &statusCode)
{
	status = statusCode;
}
