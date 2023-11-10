#include "Queue.hpp"
#include <sys/_types/_ssize_t.h>


std::string extractConnectionFromHead(const std::string &header)
{
	size_t connectionPos = header.find("Connection: ");
	std::string connection;

	if (connectionPos != std::string::npos)
	{
		size_t connectionStart = connectionPos + 12;
		size_t connectionEnd = header.find("\r\n", connectionStart);
		connection = header.substr(connectionStart, connectionEnd - connectionStart);
	}
	
	return(connection);
}

Queue::Queue() {

	this->kq = 0;
	this->nev = 0;
	std::memset(&this->evSet, 0, sizeof(this->evSet));
	std::memset(&this->evConn, 0, sizeof(this->evConn));
	std::memset(&this->evList, 0, sizeof(this->evList));
	std::memset(&this->buffer, 0, sizeof(this->buffer));
	this->imageData.clear();
	std::memset(&this->bufferTemp, 0, sizeof(this->bufferTemp));
	this->typeConnection = false;
	return;
}

Queue::Queue(const Queue &obj) {

	*this = obj;

	return;
}

Queue::~Queue() {
	
	return;
}

Queue	&Queue::operator=(const Queue &obj) {

	this->kq = obj.kq;
	this->nev = obj.nev;
	this->evSet = obj.evSet;
	this->evConn[0] = obj.evConn[0];
	this->evConn[1] = obj.evConn[1];
	*this->buffer = *obj.buffer;
	this->imageData = obj.imageData;
	this->bufferTemp = obj.bufferTemp;
	this->typeConnection = obj.typeConnection;

	return *this;
}

int		Queue::getKq() const {

	return this->kq;
}

int		Queue::getNev() const {

	return this->nev;
}

struct kevent	Queue::getEvList(const int i) const {

	return this->evList[i];
}

char*	Queue::getBuffer() {

	return this->buffer;
}

bool	Queue::getTypeConnection() const {

	return this->typeConnection;
}

void	Queue::setTypeConnection(const std::string _type) {

	if (_type.compare("close") == 0)
		this->typeConnection = false;

	else if (_type.compare("keep-alive") == 0)
		this->typeConnection = true;

	else
		printError("Error: no matching of type connection");

	return;
}

int		Queue::ft_queueCreate() {

	this->kq = kqueue();
	if (this->kq == -1) {
		printError("Error: queue created error");
		return (-1);
	}

	return (0);
}

int		Queue::ft_eventIntro(int opt, const int sock) {

	switch (opt) {
		case 1: 
			EV_SET(&this->evSet, sock, EVFILT_READ, EV_ADD, 0, 0, NULL);
			if (kevent(this->kq, &this->evSet, 1, NULL, 0, NULL) == -1) {
				printError("Error: introducing READ event");
				return (-1);
			}
			break;

		case 2:
			EV_SET(&this->evSet, sock, EVFILT_WRITE, EV_ADD | EV_DISABLE, 0, 0, NULL);
			if (kevent(this->kq, &this->evSet, 1, NULL, 0, NULL) == -1) {
				printError("Error: introducing WRITE event");
				return (-1);
			}
			break;	

		case 3:
			EV_SET(&this->evSet, sock, EVFILT_WRITE, EV_ENABLE, 0, 0, NULL);
			if (kevent(this->kq, &this->evSet, 1, NULL, 0, NULL) == -1) {
				printError("Error: enabiling WRITE event");
				return (-1);
			}
			break;

		case 4:
			EV_SET(&this->evSet, sock, EVFILT_READ, EV_DELETE, 0, 0, NULL);
			if (kevent(this->kq, &this->evSet, 1, NULL, 0, NULL) == -1) {
				printError("Error: deleting READ event");
				return (-1);
			}
			break;

		case 5:
			EV_SET(&this->evSet, sock, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
			if (kevent(this->kq, &this->evSet, 1, NULL, 0, NULL) == -1) {
				printError("Error: deleting WRITE event");
				return (-1);
			}
			break;
		case 6:
			EV_SET(&this->evSet, sock, EVFILT_WRITE, EV_DISABLE, 0, 0, NULL);
			if (kevent(this->kq, &this->evSet, 1, NULL, 0, NULL) == -1) {
				printError("Error: disabling WRITE event");
				return (-1);
			}
			break;
	}
	std::memset(&this->evSet, 0, sizeof(this->evSet));
	return (0);
}

int		Queue::ft_eventCheck() {

	this->nev = kevent(this->kq, NULL, 0, this->evList, 25, NULL);
	if (this->nev < 1) {
		printError("Error: no event to analyce");
		return (-1);
	}

	return (0);
}

int		Queue::ft_accept(int i) {

	struct sockaddr_in		clientAddr;
	socklen_t				clientAddrLen = sizeof (clientAddr);
	int						clientSock;

	clientSock = accept(this->evList[i].ident, (struct sockaddr *)&clientAddr, &clientAddrLen);
	if (clientSock == -1) {
		printError("Error: acept error");
		return (-1);
	}

	return clientSock;
}

int		Queue::ft_read(const int sock) {

	ssize_t		totalBytesRead;
	int			hasContentLength;
	ssize_t		contentLength;
	int			bytesRead;
	std::string line;

	contentLength = 0;
	hasContentLength =  1;
	totalBytesRead = 0;

	line.clear();

	while ((bytesRead = recv(sock, this->buffer, sizeof(this->buffer), 0)) > 0)
	{
		this->imageData.append(this->buffer, bytesRead);
		totalBytesRead += bytesRead;
		if (hasContentLength == 1)
		{
			std::istringstream iss(this->imageData);
			while (std::getline(iss, line)) 
			{
				if (line.substr(0, 14) == "Content-Length") 
				{
					hasContentLength = 0;
					contentLength = std::stoi(line.substr(16));
					break;
				}
			}
		}
		if (imageData.find("0\r\n\r\n") != std::string::npos)
			break;
		else if (totalBytesRead >= contentLength && hasContentLength == 0)
			break;
		else if (imageData.find("\r\n\r\n") != std::string::npos && bytesRead < 1024 && imageData.find("Transfer-Encoding: chunked") == std::string::npos)
			break;
	}

//checkeo el tipo de conexion
	setTypeConnection(extractConnectionFromHead(this->buffer));       
	return (0);
}

//funcion que escribe al cliente
int		Queue::ft_write(const int sock, Config *conf_file) {//anadir como parametro de la function ft_write el

	ssize_t		bytesSend;
	
	bytesSend = conf_file->server_data(sock, this->imageData);
	imageData.clear();

	if (bytesSend == -1) {
		printError("Error: write error");
		return (-1);
	}

	return (0);
}
