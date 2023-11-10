#include "User.hpp"

User::User()
{}
User::~User(){}

User::User(const User& other) 
{
    username = other.username;
    password = other.password;
}


User& User::operator=(const User& other) 
{
    if (this != &other) {
        username = other.username;
        password = other.password;
    }
    return *this;
}

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

std::string User::getUsername() const 
{
    return username;
}

std::string User::getPassword() const 
{
    return password;
}
