#include "Server.hpp"
#include "UtilityFunctions.hpp"

Server::Server() {

	return;
}

Server::Server(const Server &obj) {

	*this = obj;

	return;
}

Server::~Server() {

	return;
}

Server		&Server::operator=(const Server &obj) {

	for (std::map<int, Sock>::const_iterator it = obj.server.begin(); it != obj.server.end(); ++it) {

		server[it->first] = it->second;
	}

	return *this;
}

int		Server::getSockPort(int numPort) {

	return this->server[numPort].getSock();
}

int		Server::ft_introSock(std::vector<int> numPort) {

	for (std::vector<int>::iterator it = numPort.begin(); it != numPort.end(); it++) {
		
		Sock		sock(*it);

		if (sock.ft_createSocket() == -1)
			return (-1);
		if (sock.ft_setupSocket() == -1)
			return (-1);
		if (sock.ft_bindSocket() == -1)
			return (-1);
		if (sock.ft_listen() == -1)
			return (-1);
		if (sock.ft_getNameSocket() == -1)
			return (-1);

		this->server.insert(std::pair<int, Sock>(*it, sock));
	}

	return (0);
}

int		Server::ft_existInServer(int clientFd) {

	for (std::map<int, Sock>::iterator it = this->server.begin(); it != this->server.end(); ++it) {
		if (it->second.getSock() == clientFd)
			return (0);
	}

	return (-1);
}

int		Server::ft_closeServer() {

	for (std::map<int, Sock>::iterator it = this->server.begin(); it != this->server.end(); ++it) {
		close (it->second.getSock());
	}

	this->server.clear();

	return (0);
}
