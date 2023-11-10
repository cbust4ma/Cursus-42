#include "Sock.hpp"
#include "UtilityFunctions.hpp"

Sock::Sock() 
{
	this->sock = 0;

	this->server.sin_family = AF_INET;
	this->server.sin_addr.s_addr = INADDR_ANY;
	this->server.sin_port = htons(80);

	std::memset(&this->addr, 0, sizeof(this->addr));
	this->addrLength = sizeof(this->addr);

	return;
}

Sock::Sock(int numPort) 
{
	this->sock = 0;

	this->server.sin_family = AF_INET;
	this->server.sin_addr.s_addr = INADDR_ANY;
	this->server.sin_port = htons(numPort);

	std::memset(&this->addr, 0, sizeof(this->addr));
	this->addrLength = sizeof(this->addr);

	return;
}

Sock::Sock(const Sock &obj) {

	*this = obj;

	return;
}

Sock::~Sock() {

	return;
}

Sock	&Sock::operator=(const Sock &obj) {

	this->sock = obj.sock;
	
	this->server.sin_family = obj.server.sin_family;
	this->server.sin_addr.s_addr = obj.server.sin_addr.s_addr;
	this->server.sin_port = obj.server.sin_port;

	this->addr = obj.addr;
	this->addrLength = obj.addrLength;

	return *this;
}

int		Sock::getSock() const {

	return this->sock;
}

int		Sock::ft_createSocket() 
{
	
	this->sock = socket(AF_INET, SOCK_STREAM, 0);
	if (this->sock == -1) {
		printError("Error: creating socket");
		return (-1);
	}
	return (0);
}

int		Sock::ft_setupSocket() {

	int		reuse = -1;

	if (setsockopt(this->sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof reuse) == -1) {
		printError("Error: set socket option wrong");
		return (-1);
	}

	return (0);
}

int		Sock::ft_bindSocket() {

	if (bind(this->sock, (struct sockaddr *) &this->server, sizeof(this->server)) == -1) {
		printError("Error: binding socket");
		close (this->sock);
		return (-1);
	}

	return (0);
}

int		Sock::ft_getNameSocket() {

	printSeparator("Getting address and port information");
	if (getsockname(this->sock, (sockaddr *) &this->addr, &this->addrLength) == -1) {
		printError("Error: getting socket name");
		close (this->sock);
		return (-1);
	}

	return (0);
}

int		Sock::ft_listen() {

	if (listen(this->sock, 25) == -1) {
		printError("Error: listening wrong");
		close (this->sock);
		return (-1);
	}

	return (0);
}

int		ft_getPortSocket(int sock) {

	int			port;
	sockaddr_in	addr;
	socklen_t	addrLength = sizeof(addr);
	
	getsockname(sock, (sockaddr*)&addr, &addrLength);
	
	port = ntohs(addr.sin_port);

	return port;
}
