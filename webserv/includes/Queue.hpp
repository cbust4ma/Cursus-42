#ifndef	QUEUE_HPP
# define QUEUE_HPP
#include <string>
#define READ_ADD 1
#define WRITE_ADD 2
#define WRITE_ENABLE 3
#define READ_DELETE 4
#define WRITE_DELETE 5
#define WRITE_DISABLE 6
 # include <sys/event.h>
 # include <iostream>
 # include <sys/socket.h>
 # include <netinet/in.h>
 #include <sstream>
 #include <Config.hpp>

 # include <vector>

class	Queue {

	private:
		int				kq;
		int				nev;
		struct kevent	evSet;
		struct kevent	evConn[2];
		struct kevent	evList[25];
		char			buffer[1024];
		std::string 	imageData;
		std::string		bufferTemp;
		bool			typeConnection;//(false = close / true = keep-alive)

	public:

//canonical functions
		Queue();
		Queue(const Queue &obj);
		~Queue();
		Queue	&operator=(const Queue &obj);

//getters and setters
		int				getKq() const;
		int				getNev() const;
		struct kevent	getEvList(int i) const;
		char*			getBuffer();
		bool			getTypeConnection() const;

		void			setTypeConnection(const std::string _type);

//methods
		int		ft_queueCreate();
		int		ft_eventIntro(int opt, int sock);
		int		ft_eventCheck();
		int		ft_accept(int i);
		int		ft_read(const int sock);
		int		ft_write(const int sock, Config *conf_file);


};

#endif
