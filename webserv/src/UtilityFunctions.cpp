#include "UtilityFunctions.hpp"
#include "HttpResponse.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#define RESET_COLOR "\033[0m"
#define GREEN_BOLD_COLOR "\033[1;32m"
#define RED_ERROR "\033[1;31m"
#define CLEAR_SCREEN "\033[2J"
#define YELLOW_BOLD_COLOR "\033[1;33m"
#define BLUE_BOLD_COLOR "\033[1;34m"

bool isSessionActive;
static bool userAdded;

std::string handleLogoutForm(StatusCode &statusCode) 
{
    std::ifstream logoutFile("session/logout.html");
    if (logoutFile)
    {
        std::ostringstream logoutContent;
        logoutContent << logoutFile.rdbuf();
        logoutFile.close();
        statusCode = OK;
        return logoutContent.str();
    }
    else
      statusCode = Unauthorized;
    return "<h1>Internal Server Error</h1>";
}

std::string handleLogout(std::string &cookie, StatusCode &statusCode, std::vector<std::pair<std::string, std::string> > &activeSessions) 
{
    bool foundSession = false;
    
    for (std::vector<std::pair<std::string, std::string> >::iterator sessionIt = activeSessions.begin(); sessionIt != activeSessions.end(); ) 
    {
        if (sessionIt->second == cookie) 
        {
            sessionIt = activeSessions.erase(sessionIt); 
            foundSession = true;
            isSessionActive = false;
            userAdded = false;
            statusCode = OK;
            cookie = "deletecookie";
            return "<h1>Sesion cerrada correctamente</h1>";
        }
        else
            ++sessionIt; 
    }
    if (!foundSession)
        statusCode = Unauthorized;
    return "<h1>No se encontro una sesion activa para cerrar</h1>";
}

std::string generateSessionToken() 
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    const int tokenLength = 20;
    std::string token;
    for (int i = 0; i < tokenLength; ++i) 
        token += alphanum[rand() % (sizeof(alphanum) - 1)];
    return token;
}

std::string GetLogin(std::string& response, const std::string& username, const std::string& password, StatusCode &statusCode,
    std::vector<std::pair<std::string, std::string> >& activeSessions, UserDataManager& userManager, std::string &sessionToken) 
{   
    std::vector<std::pair<std::string, std::string> >::iterator sessionIt;

    for (sessionIt = activeSessions.begin(); sessionIt != activeSessions.end(); ++sessionIt) 
    {
        if (sessionIt->first == username) 
        {
            sessionToken = sessionIt->second;
            response += "<h1>Welcome Again, " + username + "!</h1>";
            response += handleLogoutForm(statusCode);
            statusCode = OK;
            break;
        }
    }
    if (sessionIt == activeSessions.end()) 
    {
        if (userManager.getUser(username).getPassword() == password) 
        {
            sessionToken = generateSessionToken();
            activeSessions.push_back(std::pair<std::string, std::string>(username, sessionToken));
            std::ofstream outFile("cookie.txt", std::ios::app);
            if (outFile.is_open()) 
            {
                std::string sep = "::";
                outFile << username + sep + sessionToken + sep + "☕" << std::endl;
                outFile.close();
            }
            response += "<h1>Bienvenida, " + username + "&#129419;!</h1>";
            response += handleLogoutForm(statusCode);
            statusCode = OK;
        }
        else 
        {
            response += "<h1>Error de autenticacion</h1>";
            statusCode = Unauthorized;
        }
    }
    return sessionToken;
}

bool handleRequest(const std::string &cookie, std::vector<std::pair<std::string, std::string> >& activeSessions, std::string &response)
{
    std::vector<std::pair<std::string, std::string> >::iterator sessionIt;
    for (sessionIt = activeSessions.begin(); sessionIt != activeSessions.end(); ++sessionIt) 
    {
        if (sessionIt->second == cookie) 
        {
            const std::string name = sessionIt->first;
            response += "<h2>Login, " + name + "!</h2>";
            return true;
        }
    }
    return false;
}

std::string handleGET(StatusCode &statusCode, std::string &responseBody, bool &isSessionActive) 
{
    if (isSessionActive)
    {
        responseBody = "<h1>Sesion activa. Bienvenido de nuevo.</h1>";
        responseBody = handleLogoutForm(statusCode);
        statusCode = OK;
    }
    else
    {
        std::ifstream loginFile("session/login.html");
        if (loginFile)
        {
            std::ostringstream loginContent;
            loginContent << loginFile.rdbuf();
            loginFile.close();
            responseBody = loginContent.str();
            statusCode = OK;
        }
        else
            statusCode = NotFound;
    }
	return (responseBody);
}

std::string handlePOST(const std::string &buffer, StatusCode &statusCode, std::string &responseBody, std::vector<std::pair<std::string, std::string> > &activeSessions,
        UserDataManager& userManager) 
{
    std::string username, password;
    size_t usernamePos = buffer.find("username=");
    size_t passwordPos = buffer.find("&password=");
    
    if (usernamePos != std::string::npos && passwordPos != std::string::npos) 
    {
        usernamePos += 9;
        passwordPos += 10;

        size_t usernameEnd = buffer.find('&', usernamePos);
        size_t passwordEnd = buffer.size();

        if (usernameEnd != std::string::npos && passwordEnd != std::string::npos) 
        {
            username = buffer.substr(usernamePos, usernameEnd - usernamePos);
            password = buffer.substr(passwordPos, passwordEnd - passwordPos);
        }
    }
    std::string sessionToken; 
    std::string token = GetLogin(responseBody, username, password, statusCode, activeSessions, userManager, sessionToken);
	return (sessionToken);
}

std::string loginCall(std::string &path, std::string &method, StatusCode &statusCode, std::string &buffer, std::string &responseBody)
{
    static std::vector<std::pair<std::string, std::string> > activeSessions;
    static std::string tokens;
    UserDataManager userManager;
    

    if (path == "/login") 
    {
        if (method == "GET") 
           responseBody = handleGET(statusCode, responseBody,isSessionActive);
        else if (method == "POST") 
        {
            std::string username = "uno";
            if (!userAdded)
            {
                User user(username, "dos");
                userManager.addUser(username, user);
                userAdded = true;
            }
            tokens = handlePOST(buffer, statusCode, responseBody, activeSessions, userManager);
            isSessionActive = handleRequest(tokens, activeSessions, responseBody);
        }
    }
    if (path == "/dologout" && method == "POST")
    {
        responseBody = handleLogout(tokens, statusCode, activeSessions);
        method = "loggin";
        statusCode = Found;
    }
    return tokens;
}

void printSeparator(const std::string& title) 
{
    std::cout << GREEN_BOLD_COLOR << "🌐 " << title << RESET_COLOR << std::endl;
    std::cout << "=============================================" << std::endl;
}

void printError(const std::string& title)
{
    std::cerr << RED_ERROR << "🌐 " << title << RESET_COLOR << std::endl;
    std::cerr << "=============================================" << std::endl;
}

void printInitClient(int connectionCount, uint16_t port)
{
    std::cout << BLUE_BOLD_COLOR << "\n=============================================" << RESET_COLOR << std::endl;
    std::cout << GREEN_BOLD_COLOR << "🌐⏳ Waiting for a connection... ⏳🌐" << RESET_COLOR << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << GREEN_BOLD_COLOR << "   Listening on IP: 0.0.0.0 "  << " Port: " << port << RESET_COLOR << std::endl;
    std::cout << GREEN_BOLD_COLOR << "   Connections established: " << connectionCount << RESET_COLOR << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << BLUE_BOLD_COLOR << "=============================================\n" << RESET_COLOR << std::endl;
}
