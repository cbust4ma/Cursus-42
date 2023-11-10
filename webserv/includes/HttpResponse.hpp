#ifndef HTTP_RESPONSE_HPP
 #define HTTP_RESPONSE_HPP
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <string>
 #include <map>
 # define  BUFFERBYTES 10

//Damos valores a los codigos de estados para luego sea mas facil utilizarlos en el mapa
enum StatusCode
{
	OK = 200,
	NotFound = 404,
	BadRequest = 400,
	Unauthorized = 401,
	InternalServerError = 500,
	RequestEntityTooLarge = 413,
	NoContent = 204,
	MethodNotAllowed = 405,
	MovedPermanently = 301,
	Found = 302,
	GatewayTimeout = 504
	//A medida que encontremos vamos añadiendo mas
};

class HttpResponse
{
	private:
		std::map<std::string, std::string> headers;
		std::stringstream bodyStream;
		std::map<StatusCode, std::string> statusHeaders;
		StatusCode status;
	public:
		HttpResponse();
		~HttpResponse();
		HttpResponse& operator=(const HttpResponse& other);
		HttpResponse(const HttpResponse& other);
		void setHeader(const std::string &key, const std::string &value);
		void setBody(const std::string &body);
		std::string getStatusHeader(StatusCode statusCode) const;
		void setStatus(StatusCode &statusCode);
		std::string getResponse() const;
		void setResponseHeaders(const std::string& contentType, const std::string& responseBody, const std::string& connection, const std::string& method, std::string msg, std::string cookies);
};

 #endif
