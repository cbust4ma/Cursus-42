#include <Config.hpp>
#include <cstddef>
#include <exception>
#include <sys/wait.h>

const char *execTypeCgi(std::string &ext, const char *PATH_INFO, const char  *executeFile, const char *dataBody)
{
	if (ext == "sh")
	{
		char *args[] = {(char *)"bash", (char *)executeFile, (char *)dataBody, nullptr};
		char *env[] = { (char *)PATH_INFO, NULL};
		execve("/bin/bash", args, env);
	}
	else if (ext == "py")
	{
		char *args[] = {(char *)"python3", (char *)executeFile, (char *)dataBody, nullptr};
		char *env[] = { (char *)PATH_INFO, NULL};
		execve("/usr/bin/python3", args, env);
	}
	return ("");
}

ssize_t controlReadExc(StatusCode &statusCode, int child_pid, std::string &data, ssize_t bytes_read, int fd[2])
{
	std::time_t start_time = std::time(NULL);
	int 		status = 0;
	char		buffer[1024];
	int			result = 0;
	int			time;

	while ((time = std::difftime(std::time(NULL), start_time)) < 5)
	{

		result = waitpid(child_pid, &status, WNOHANG);
		if (result > 0)
		{
			while ((bytes_read = read(fd[0], buffer, sizeof(buffer))) > 0)
			{
				data.append(buffer, bytes_read);
				statusCode = OK;
			}
			if (bytes_read == 0)
				break;
		}
	}
	if (time > 4)
	{
		statusCode = GatewayTimeout;
		kill(child_pid, SIGKILL);
	}
	return bytes_read;
}


std::string Config::cgiPostController(std::string path, const char *dataBody, StatusCode &statusCode)
{
	std::string ext = path.substr(path.find_last_of("/") + 1);
	ext = ext.substr(ext.find_last_of(".") + 1);
	std::map<std::string, bool>::iterator it;
	
	if (ext == "py")
		return (execCgiPython(path, dataBody, statusCode, ext));
	else if (ext == "sh")
		return (execCgiPython(path, dataBody, statusCode, ext));

	return ("");
}

std::string Config::execCgiPython(std::string path, const char *dataBody, StatusCode &statusCode, std::string &ext)
{
	int fd[2];

	ssize_t bytes_read = 0;
	const char *executeFile = static_cast<const char *>(path.c_str()); 
	std::string data;
	std::fstream file;
	std::string process = std::string(path + "?" + dataBody);
	const char *PATH_INFO = process.c_str();
	setenv("PATH_INFO", PATH_INFO, 1);
	
	if (pipe(fd) < 0)
		return 	NULL;
	pid_t child_pid = fork();
	if (child_pid == -1) 
		return "";
	if (child_pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		dataBody = execTypeCgi(ext, PATH_INFO, executeFile, dataBody);
		exit(1); 
	} 
	else
	{
		close(fd[1]);
		bytes_read = controlReadExc(statusCode, child_pid, data, bytes_read, fd);
		close(fd[0]);
		
		wait(nullptr);
	}
	dataBody = nullptr;
	return(data);
}


int Config::httpPostCgi(const std::string& requestData, int client_fd, std::string path) 
{
	int bytesSent = 0;
	StatusCode statusCode;
	std::string responseBody = "<h1>Enviado </h1>";
	
	std::string filename = path.substr(path.find_last_of("/") + 1);
	std::string output = cgiPostController(path, removeHeaderCgi(requestData.c_str()), statusCode);
	if (statusCode == GatewayTimeout)
		return sendResponse(statusCode, "text/html", PageErrorCode(statusCode), client_fd, extractConnectionFromHeader(requestData),"", "", "");
	else if (!output.empty()) 
	{
		statusCode = OK;
		responseBody = "<h1>Scrpit ejecutado correctamente</h1> <h2>" + output + "</h2>";
		bytesSent = sendResponse(statusCode, "text/html", responseBody, client_fd, extractConnectionFromHeader(requestData),"", "", "");
	} 
	else
	{
		statusCode = InternalServerError;
		bytesSent = sendResponse(statusCode, "text/html", PageErrorCode(statusCode), client_fd, extractConnectionFromHeader(requestData),"", "", "");
	}
	filename.clear();
	return (bytesSent);
}

int Config::httpGetCgi(const std::string& requestData, int client_fd, std::string path) 
{
	int bytesSent = 0;
	StatusCode statusCode;
	std::string responseBody = "<h1>Enviado </h1>";
	
	std::string filename = path.substr(path.find_last_of("/") + 1);
	std::string data_body;
	size_t query_pos = path.find('?');
	if (query_pos != std::string::npos)
	{
		data_body = path.substr(query_pos + 1);
		path = path.substr(0, query_pos);
	}
	std::string output = cgiPostController(path, data_body.c_str(), statusCode);
	
	if (statusCode == GatewayTimeout)
		return sendResponse(statusCode, "text/html", PageErrorCode(statusCode), client_fd, extractConnectionFromHeader(requestData),"", "", "");
	else if (!output.empty()) 
	{
		statusCode = OK;
		responseBody = "<h1>Scrpit ejecutado correctamente GET </h1> <h2>" + output + "</h2>";
		bytesSent = sendResponse(statusCode, "text/html", responseBody, client_fd, extractConnectionFromHeader(requestData),"", "", "");
	} 
	else
	{
		statusCode = InternalServerError;
		bytesSent = sendResponse(statusCode, "text/html", PageErrorCode(statusCode), client_fd, extractConnectionFromHeader(requestData),"", "", "");
	}
	filename.clear();
	
	return (bytesSent);
}
