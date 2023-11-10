#ifndef USERDATAMANAGER_HPP
 #define USERDATAMANAGER_HPP
 #include <map>
 #include <string>
 #include "User.hpp"
 #include <stdexcept>

class UserDataManager 
{
	private:
		std::map<std::string, User> userDatabase;
		std::map<std::string, std::pair<std::string, bool> > activeSessions;
		bool userAdded;
		bool isSessionActive;
	public:
		UserDataManager();
		~UserDataManager();
		UserDataManager(const UserDataManager& other);
		UserDataManager& operator=(const UserDataManager& other);
		void addUser(const std::string& username, const User& user);
		User getUser(const std::string& username);
		void addActiveSession(const std::string& username, const std::string& sessionToken, bool isActive);
		std::pair<std::string, bool> getActiveSession(const std::string& username);
		bool getUserAdded() const;
		bool getIsSessionActive() const;
		void setUserAdded(bool user);
		void setIsSessionActive(bool session);
};
#endif
