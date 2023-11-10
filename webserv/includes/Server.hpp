#ifndef SERVER_HPP
# define SERVER_HPP

#include "Sock.hpp"
# include <map>
# include <vector>

class	Server {

	private:
		std::map<int, Sock>		server;
		

	public:

//canonical functions		
		Server();
		Server(const Server &obj);
		~Server();
		Server	&operator=(const Server &obj);

//getters and setters
		
		int		getSockPort(int port);

//methods
		int		ft_introSock(std::vector<int> numPort);
		int		ft_existInServer(int clientFd);
		int		ft_closeServer();
};

#endif
