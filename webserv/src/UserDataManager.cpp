#include "UserDataManager.hpp"
#include "User.hpp"
#include <iostream>

UserDataManager::UserDataManager()
 {
	this->userAdded = false;
	this->isSessionActive = false;
 }

UserDataManager::UserDataManager(const UserDataManager& other) 
{
    userDatabase = other.userDatabase;
    activeSessions = other.activeSessions;
    userAdded = other.userAdded;
    isSessionActive = other.isSessionActive;
}

// Sobrecarga del operador de asignación
UserDataManager& UserDataManager::operator=(const UserDataManager& other) 
{
    if (this != &other) {
        userDatabase = other.userDatabase;
        activeSessions = other.activeSessions;
        userAdded = other.userAdded;
        isSessionActive = other.isSessionActive;
    }
    return *this;
}

bool UserDataManager::getUserAdded() const
{
	return this->userAdded;
}

bool UserDataManager::getIsSessionActive() const
{
	return this->isSessionActive;
}

void UserDataManager::setUserAdded(bool user)
{
   this->userAdded = user;     
}

void UserDataManager::setIsSessionActive(bool session)
{
	this->isSessionActive = session;
}

UserDataManager::~UserDataManager() {}

void UserDataManager::addUser(const std::string& username, const User& user) 
{
	userDatabase[username] = user;
}

User UserDataManager::getUser(const std::string& username) 
{
	if (userDatabase.find(username) != userDatabase.end()) 
		return userDatabase[username];
	else 
		return (User());
}

void UserDataManager::addActiveSession(const std::string& username, const std::string& sessionToken, bool isActive) 
{
	activeSessions[username] = std::make_pair(sessionToken, isActive);
}

std::pair<std::string, bool> UserDataManager::getActiveSession(const std::string& username)
 {
	if (activeSessions.find(username) != activeSessions.end()) 
	{
		return activeSessions[username];
	} 
	else 
	{
		throw std::runtime_error("Session not found");
	}
}

