#include "Sock.hpp"
#include "Queue.hpp"
#include "HttpResponse.hpp"
#include "Server.hpp"

int main(int argc, char **argv)
{

	int 						num_servers;
	std::vector<Config *> 		config_vector;
	Config						*my_config;
	std::vector<int> 			ports;
	std::map<int, Config *>		port_map;
	std::string 				file;

	if (!general_check(argc, argv))
		return(-1);
	
	file = open_file(argv[1]);
	if (!number_of_brace(file))
		return(-1);
	else
	{
		int start = 0;
		if ((num_servers = number_of_section(file, "server")) == 0) {
            printError("Error: bad format in the configuration file");
            return (-1);
        }
		try
		{
			for (int i = 1; i <= num_servers; i++)
			{
				my_config = new Config(get_info_of_section(file, "server", start));
				config_vector.push_back(my_config);
				start += get_info_of_section(file, "server", start).length();
			}
		}
		catch(const std::exception& e)
		{
			printError(e.what());

			for (size_t i = 0; i < config_vector.size(); ++i)
				delete config_vector[i];
			return (-1);
		}
	}

	for (size_t i = 0; i < config_vector.size(); ++i)
    {
		if (!config_vector[i]->minimumFile())
			{
				printError("Error: bad format in the configuration file");
				for (size_t i = 0; i < config_vector.size(); ++i)
					delete config_vector[i];
				return (-1);
			}
		std::vector<int> tmp_ports = config_vector[i]->get_ports();
		for (size_t j = 0; j < tmp_ports.size(); ++j)
		{
			port_map[tmp_ports[j]] = config_vector[i];
			ports.push_back(tmp_ports[j]);
		}
	}	

	for (size_t i = 0; i < config_vector.size(); ++i)
    {
		std::map<int, std::string> map = config_vector[i]->get_error_pages();
    	std::map<int, std::string>::const_iterator it;

    	for (it = map.begin(); it != map.end(); ++it) {
    	    if (it->second.substr(0, 13) != "./errorPages/")
			{
				for (size_t i = 0; i < config_vector.size(); ++i)
					delete config_vector[i];
				printError("Error: wrong route in error page");
				return (-1);
			}
    	}
		if (config_vector[i]->get_body_size() > 2048000)
		{
			printError("Error: u cant upload a file bigger than 2048000 bytes");
			for (size_t i = 0; i < config_vector.size(); ++i)
				delete config_vector[i];
			return (-1);			
		}
	}
	if (is_int_repeated(ports))
	{
		for (size_t i = 0; i < config_vector.size(); ++i)
			delete config_vector[i];
		return (-1);
	}

//creo el servidor
	Server		server;

//añado tantos sockets como puertos tenga
	printSeparator("Server Configuration");
	printSeparator("Creating Socket");
	printSeparator("Socket Configuration");
	printSeparator("Linking Server");
	server.ft_introSock(ports);

//creo la cola de eventos
	Queue		kq;

	kq.ft_queueCreate();
	printSeparator("Creating Event Queue...");
	for (std::vector<int>::iterator it = ports.begin(); it != ports.end(); it++)
		kq.ft_eventIntro(READ_ADD, server.getSockPort(*it));

	int				clientSocket;
	int				clientLocalPort;
	int connectionCount = 0;
	while (true) 
	{
		
		if (kq.ft_eventCheck() == -1)
			continue;

		for (int i = 0; i < kq.getNev(); i++) {
			
			clientSocket = kq.getEvList(i).ident;
		
			clientLocalPort = ft_getPortSocket(clientSocket);
			printInitClient(connectionCount, clientLocalPort);
    		connectionCount++;

			if (kq.getEvList(i).flags & EV_EOF)
				close(clientSocket);

			else if (server.ft_existInServer(clientSocket) == 0) {
				
				if ((clientSocket = kq.ft_accept(i)) == -1)
					close(clientSocket);

				if (kq.ft_eventIntro(READ_ADD, clientSocket) == -1)
					close(clientSocket);

				if (kq.ft_eventIntro(WRITE_ADD, clientSocket) == -1)
					close(clientSocket);
			}

			else if (kq.getEvList(i).filter == EVFILT_READ) {

				printSeparator("Receiving information from client");
				if (kq.ft_read(clientSocket) == -1)
					close(clientSocket);

				if (kq.ft_eventIntro(WRITE_ENABLE, clientSocket) == -1)
					close(clientSocket);
			}

			else if (kq.getEvList(i).filter == EVFILT_WRITE) {
				
				printSeparator("Processing Client information");
				if (kq.ft_write(clientSocket, port_map[clientLocalPort]) == -1)
					close(clientSocket);
				
				if (kq.ft_eventIntro(WRITE_DISABLE, clientSocket) == -1) {
					close(clientSocket);
					continue;
				}
			
				if (!kq.getTypeConnection())
					close(clientSocket);
			}
			printSeparator("Closing client connection");
		}
	}

	close(kq.getKq());
	server.ft_closeServer();
	
	return 0;
}
