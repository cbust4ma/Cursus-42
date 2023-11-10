#ifndef UTILITY_FUNCTIONS_HPP
#define UTILITY_FUNCTIONS_HPP

#include <string>
#include <vector>
#include "User.hpp" 
#include "UserDataManager.hpp" 
#include "HttpResponse.hpp" 

/********************************************************************************
 *                           Functions Login                            	    *
 ********************************************************************************/

std::string generateSessionToken();
std::string GetLogin(std::string& response, const std::string& username, const std::string& password, StatusCode &statusCode, std::vector<std::pair<std::string, std::string> > &activeSessions);
bool handleRequest(const std::string &cookie, std::vector<std::pair<std::string, std::string> > &activeSessions, std::string &response);
std::string handlePOST(const std::string &buffer, StatusCode &statusCode, std::string &responseBody, std::string &cookies, std::vector<std::pair<std::string, std::string> > &activeSessions);
std::string handleGET(StatusCode &statusCode, std::string &responseBody, bool &isSessionActive);
std::string loginCall(std::string &path, std::string &method, StatusCode &statusCode, std::string &buffer, std::string &cookies);


/********************************************************************************
 *                           Functions Logout                     			    *
 ********************************************************************************/

std::string handleLogout(std::string &cookie, StatusCode &statusCode, std::vector<std::pair<std::string, std::string> > &activeSessions);
std::string handleLogoutForm(StatusCode &statusCode);

void 		printSeparator(const std::string& title);
void 		printError(const std::string& title);
void 		printInitClient(int connectionCount, uint16_t port);
#endif
