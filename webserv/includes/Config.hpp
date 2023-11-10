/******************
*  Sockets		  *
*******************/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/event.h>
#include <netdb.h>
#include <fcntl.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/******************
*  Basics		  *
*******************/

#include <unistd.h>
#include <signal.h>

/******************
*  Strings		  *
*******************/

#include <cstring>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>

/******************
*  Containers	  *
*******************/

#include <map>
#include <vector>
#include <algorithm>
#include <iterator>


/**************************
*  Directory and  Others  *
***************************/

#include <dirent.h>
#include <cerrno>
#include <sys/_types/_ssize_t.h>
#include <sys/cdefs.h>

/******************
*  Other CLass    *
*******************/

#include "Location.hpp"
#include "HttpResponse.hpp"
#include "UtilityFunctions.hpp"
#include "UserDataManager.hpp"

#ifndef CONFIG_HPP
#define CONFIG_HPP


class Config
{
	private:
		std::string 						server_name;
		std::vector<std::string>  			host_name;
		int 								body_size;
		std::string							file;
		std::map<int, std::string> 			error_pages;
		std::vector<Location *>				location;
		std::vector<int> 					ports;

		
		//Init Config Functions
		std::string					extract_string_param_info(std::string param);
		int							extract_int_param_info(std::string param);
		int							init_listen_info(std::string param);
		int							number_of_location();
		void						init_ports();
		std::string					extarct_info_of_location(size_t start);
		bool						add_error_page_info();
		bool						init_error_page(int error, std::string path);

	public:
		Config();
		Config(std::string file_name);
		Config(const Config &obj);
		~Config();
		Config	&operator=(const Config &obj);	

//data managament functions

		/********************************************************************************
 		*                 Parser Header Http functions configHeader.cpp            		*
 		********************************************************************************/

		std::string extractFilenameFromHeader(const std::string& header);
		std::string extractBoundaryFromHeader(const std::string& header);
		std::string extractConnectionFromHeader(const std::string &header);
		std::string removeHeaderChunk(const std::string& requestData);
		std::string removeHeader(const std::string& requestData);
		int 		contentHeader(const std::string &imageData);
		const char* removeHeaderCgi(const char* requestData);
		std::string extractHostFromHeader(const std::string &header);
		bool 		valid_cgi_filename(Location *location, std::string filename, std::string method);


		/********************************************************************************
 		*                    Config Utils functions configUtils.cpp               		*
 		********************************************************************************/

		std::string autoIndex(std::string path);
		std::string PageErrorCode(StatusCode statusCode);
		ssize_t 	initUser(std::string path, std::string method, std::string data, const int client_fd);
		bool 		isDirectory(const std::string& path);
		std::string extractInitialDirectory(const std::string& path);
		bool 		hasFilenameExtension(const std::string& path);
		bool 		minimumFile();
		bool 		fileExists(const std::string& path);
		bool 		file_exist(std::string file_name);
		std::vector<std::pair<std::string, std::string> > 	initRoutes(std::string path); 
		std::string 									  	setTypeRoute(std::string extension);
		std::string 									  	toChar(int n);
		void												init_host_name();
		
		/********************************************************************************
 		*             Send information Client functions  configResponse.cpp     		*
 		********************************************************************************/

		ssize_t		server_data(const int client_fd, std::string data);
		ssize_t 	getData(std::string &data, int client_fd, Location *my_location, std::string &path, StatusCode &statusCode);
		ssize_t 	sendResponse(StatusCode statusCode, std::string contentType, std::string responseBody, int client_fd, std::string connection, std::string method, std::string msg, std::string cookies);
		ssize_t 	sendAll(int socket, const char* buffer, size_t length);
		std::string	sendNotAllowedMsg(Location *my_location);
		
		/********************************************************************************
 		*               Get, Post, Delete functions configMethods.cpp              		*
 		********************************************************************************/

		int 		httpPost(const std::string& requestData, int client_fd, Location *location);
		int 		saveImageDataToFile(const std::string& imageData, const std::string& filename, Location *location);
		int 		httpDelete (std::string header, int client_fd, std::string filename, Location *location);
		

		/********************************************************************************
 		*                   cgi functions	configCgi.cpp     		               		*
 		********************************************************************************/

		std::string	execCgiPython(std::string path, const char *dataBody, StatusCode &statusCode, std::string &ext);
		std::string	cgiPostController(std::string path, const char *dataBody, StatusCode &statusCode);
		std::string execCgiBash(std::string path, const char *dataBody, StatusCode &statusCode);
		int 		httpPostCgi(const std::string& requestData, int client_fd, std::string path);
		int 		httpGetCgi(const std::string& requestData, int client_fd, std::string path);
	
	
		/********************************************************************************
 		*                        Getters			                     				*
 		********************************************************************************/

		std::string 				get_server_name() const;
		bool		 				get_host_name(std::string my_host_name) const;
		std::map<int, std::string>	get_error_pages() const;
		unsigned long  				get_body_size() const;
		std::string 				get_error_page(int error_num) const;
		std::vector<int> 			get_ports() const;
		std::vector<Location *>	 	get_location_vector() const;
		Location*				 	get_location(std::string location_name) const;

};

int				number_of_section(std::string file_name, std::string param);
int				number_of_section_bracket(std::string file_name);
std::string		get_info_of_section(std::string file_name, std::string param, int start);

std::string		open_file(std::string file);
bool	 		number_of_brace(std::string file_name);
bool 			general_check(int argc, char **argv);
bool 			is_int_repeated(const std::vector<int>& vec);
bool 			is_numeric(const std::string& str);
#endif
