#ifndef USER_HPP
 #define USER_HPP


#include <string>

	class User 
	{
		private:
			std::string username;
			std::string password;

		public:
			User(const std::string& username, const std::string& password);
			User();
			~User();
			User& operator=(const User& other);
			User(const User& other);
			std::string getUsername() const;
			std::string getPassword() const;
			
			// Otros métodos y atributos relevantes para un usuario
	};
	#endif
