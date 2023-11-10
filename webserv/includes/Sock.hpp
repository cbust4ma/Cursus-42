#ifndef SOCK_HPP
# define SOCK_HPP

# include <iostream>
# include <sys/socket.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <arpa/inet.h>

class	Sock {
	
	private:
		int					sock;
		struct sockaddr_in	server;
		sockaddr_in			addr;
		socklen_t			addrLength;

	public:

//canonical functions
		Sock();
		Sock(int numPort);
		Sock(const Sock &obj);
		~Sock();
		Sock	&operator=(const Sock &obj);

//getters and setters
		int		getSock() const;

//methods
		int		ft_createSocket();
		int		ft_setupSocket();
		int		ft_bindSocket();
		int		ft_getNameSocket();
		int		ft_listen();

	
};

		int		ft_getPortSocket(int sock);

#endif
