#include "Config.hpp"
#include <type_traits>
#include <utility>

Config::Config()
{}

Config::Config(const Config &obj) {

	*this = obj;

	return;
}

Config::~Config()
{
	for (std::vector<Location *>::size_type i = 0; i < location.size(); ++i)
		delete location[i];
}

Config		&Config::operator=(const Config &obj) {

	this->server_name = obj.server_name;
	this->file = obj.file;
	this->body_size = obj.body_size;
	for (std::vector<std::string>::const_iterator it = obj.host_name.begin(); it != obj.host_name.end(); ++it)
		this->host_name.push_back(*it);
	for (std::vector<Location *>::const_iterator it = obj.location.begin(); it != obj.location.end(); ++it)
		this->location.push_back(*it);
	for (std::vector<int>::const_iterator it = obj.ports.begin(); it != obj.ports.end(); ++it)
		this->ports.push_back(*it);	
	for (std::map<int, std::string>::const_iterator it = obj.error_pages.begin(); it != obj.error_pages.end(); ++it)
		this->error_pages[it->first] = it->second;

	return *this;
}

std::string getMyIp() 
{
    std::string 	myIp = "";
    char 			hostname[256];

    if (gethostname(hostname, sizeof(hostname)) == 0) 
	{
        struct hostent *host_info = gethostbyname(hostname);
        if (host_info != nullptr && host_info->h_addr_list[0] != nullptr) 
		{
            struct in_addr address;
            memcpy(&address, host_info->h_addr_list[0], sizeof(struct in_addr));
            myIp = inet_ntoa(address);
            return myIp;
        }
    }
    return myIp;
}

Config::Config(std::string file)
{
	this->file = file;
	this->server_name = extract_string_param_info("server_name");
	this->body_size = extract_int_param_info("body_size");
	init_host_name();
	add_error_page_info();
	init_ports();
	Location	*my_location;
	int num = number_of_location();
	for (int i = 1; i <= num; i++)
	{
		my_location = new Location(extarct_info_of_location(i));
		location.push_back(my_location);
	}
	if (get_location("/default") != NULL || get_location("/login") != NULL
		|| get_location("/logout") != NULL || get_location("/dologout") != NULL || get_location("/errorPages") != NULL)
		throw std::invalid_argument("Invalid argument reserved for system...");
	if (get_location("/") == NULL)
	{
		my_location = new Location();
		my_location->set_get(true);
		my_location->set_post(false);
		my_location->set_delete(false);
		my_location->set_path("/default/");
		my_location->set_index("index.html");
		my_location->set_autoindex(false);
		my_location->set_redirectBool(false);
		location.push_back(my_location);
		
	}
	my_location = new Location();
	my_location->set_get(true);
	my_location->set_post(false);
	my_location->set_delete(false);
	my_location->set_path("/errorPages");
	//my_location->set_index("index.html");
	my_location->set_autoindex(false);
	my_location->set_redirectBool(false);
	location.push_back(my_location);	
	if (!host_name.empty())
	{
		host_name.push_back("127.0.0.1");
		for (size_t i = 0; i < ports.size(); i++) 
		{
    	    host_name.push_back(std::string("127.0.0.1:") + toChar(ports[i]));
			host_name.push_back(std::string("localhost:") + toChar(ports[i]));
			host_name.push_back(getMyIp() + ":" + toChar(ports[i]));
    	}
	}
}

bool general_check(int argc, char **argv)
{
	std::ifstream	file_fd;

	if (argc != 2) {
		printError("Error: bad number of arguments");
		return false;
	}

	std::string		file(argv[1]);

	if(file.substr(file.find_last_of(".") + 1) != "conf") {
		printError("Error: bad file extension");
		return false;
	}

	file_fd.open(argv[1]);
	if (file_fd.good() == false) {
		printError("Error: file does not exists");
		return false;
	}
	file_fd.close();
	return true;
}

int Config::number_of_location()
{
    int count;
    std::istringstream file(this->file);
    std::string token;

	count = 0;
    while (file >> token) 
	{
		if (token == "location")
            count++;
    }
    return count;
}

std::string Config::extract_string_param_info(std::string param)
{
	size_t start;
	size_t end;
	std::string line;
	std::string answ;
 
	start = 0;
	answ = "";
	end = this->file.find(';' ) + 1;
	while (file.find(";", start) != std::string::npos)
	{
		line =  file.substr(start, end - start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		if (param == line.substr(0, param.length()))
			answ = line.substr(param.length() + 1, line.length() - param.length() - 2);
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}
	return answ;
}

bool is_numeric(const std::string& str)
{
	int	n;

	n = 0;
	std::stringstream ss(str);
    if (!(ss >> n && ss.eof()) || str.find('-') != std::string::npos)
	{
		printError("Error: No int");
		return false;
	}
	return true;
}

int Config::extract_int_param_info(std::string param)
{
	size_t start;
	size_t end;
	std::string line;
	std::string answ;
 
	start = 0;
	answ = "";
	end = this->file.find(';') + 1;

	while (file.find(";", start) != std::string::npos)
	{
		line =  file.substr(start, end - start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
		if (param == line.substr(0, param.length()))
			answ = line.substr(param.length() + 1, line.length() - param.length() - 2);
		else if (line.substr(0, 8) == "location")
			end = this->file.find("};", start) + 1;
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}

	if (is_numeric(answ) && answ != "")
		return std::stoi(answ);
	return (-1);
}

void Config::init_ports()
{
	size_t start;
	size_t end;
	std::string line;
	std::string param;
	int port;

 
	start = 0;
	param = "listen";
	end = this->file.find(';') + 1;
	while (file.find(";", start) != std::string::npos)
	{
		line =  file.substr(start, end - start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		if (param == line.substr(0, param.length()))
		{
			if (is_numeric(line.substr(param.length() + 1, line.length() - param.length() - 2)))
			{
				port = std::stoi(line.substr(param.length() + 1, line.length() - param.length() - 2));
				ports.push_back(port);
			}
		}
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}
}

bool	Config::add_error_page_info()
{
	size_t start;
	size_t end;
	std::string line;
	std::string answ;
	std::string param;
	std::string str;
	int num;
 
	start = 0;
	param = "error_page";
	end = this->file.find(';') + 1;
	while (file.find(";", start) != std::string::npos)
	{
		line =  file.substr(start, end - start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		std::istringstream my_file(line);
		my_file >> str;
		if (param == str)
		{
			my_file >> str;
			if (!is_numeric(str))
				return false;
			num = std::stoi(str);
			my_file >> str;
			init_error_page(num, str);
		}
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}
	return true;
}

bool Config::init_error_page(int error, std::string path)
{
	std::map<int, std::string>::iterator it;
	
	it = error_pages.find(error);
	if (it != error_pages.end())
		return false;
	error_pages[error] = "." + path.substr(0, path.length() - 1);
	return true;
	
}

std::string open_file(std::string file_name)
{
    std::ifstream 		file(file_name);
	std::stringstream 	my_file;

    if (file.fail()) 
        throw std::runtime_error("Failed to open file: ");
    my_file << file.rdbuf(); 
    file.close();
	return my_file.str();
}

std::string get_info_of_section(std::string my_file, std::string param, int start)
{
	size_t end;
	int open_section;
	int i;

	end = 0;
	i = 0;
	open_section = -1;
	my_file.erase(std::remove(my_file.begin(), my_file.end(), '\t'), my_file.end());
	start = my_file.find(param, start) + param.length() + 1;
	std::string::iterator it = my_file.begin() + start;
	while (it != my_file.end()) 
	{
		if (*it == '{')
			open_section++;
		else if (*it == '}' && open_section > 0)
			open_section--;
		else if (*it == '}')
		{
			end = std::distance(my_file.begin(), it);
			break ;
		}
		it++;
    }
	it = my_file.begin() + end;
	while (*it != '}')
		it ++;
	end = std::distance(my_file.begin(), it) + 1;
	it = my_file.begin() + start;
	while (*it != '{')
		it ++;
	start = std::distance(my_file.begin(), it) + 2;
	return my_file.substr(start, end - start);
} 

std::string Config::extarct_info_of_location(size_t start)
{
	size_t i;
	size_t end;
	std::string line;
	std::string answ;
	std::string param;
	size_t line_start;

	end = file.find(";") + 1;
	line_start = 0;
	i = 1;
	param = "location";

	while (file.find(";", line_start) != std::string::npos)
	{
		line = file.substr(line_start, end - line_start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
		
		if (param == line.substr(0, param.length()))
		{
			if (start != i)
				i++;
			else
			{
				end = this->file.find("};", start) + 1;
				line = file.substr(line_start, end - line_start);
				break ;
			}
		}
		line_start = end + 1;
		end = this->file.find(';', line_start) + 1;
	}
	return line;
} 

bool is_int_repeated(const std::vector<int>& vec)
{
    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
	{
		if (vec[i] < 2 || vec[i] > 65535)
			{
				printError("Error: Not in range of ports");
				return true;
			}
        for (std::vector<int>::size_type j = i + 1; j < vec.size(); ++j)
		{
            if (vec[i] == vec[j])
			{
				printError("Error: port repeated");
                return true;
			}
		}
    }
	return false;
}


std::vector<int> Config::get_ports() const
{
	return ports;
}

std::map<int, std::string> Config::get_error_pages() const
{
	return error_pages;
}

std::string Config::get_server_name() const
{
	return server_name;
}


unsigned long Config::get_body_size() const
{
	if (body_size < 0)
		return 0;
	return body_size;
}

std::string Config::get_error_page(int error_num) const
{

	if (error_pages.find(error_num) != error_pages.end())
		return error_pages.find(error_num)->second;
	return "nocode";
}

bool Config::get_host_name(std::string my_host_name) const
{

	for (size_t i = 0; i < host_name.size(); i++)
	{
		if (host_name[i] == my_host_name)
			return true;
    }
	return false;
}

std::vector<Location *>	 Config::get_location_vector() const
{
	return location;
}

Location* 	Config::get_location(std::string location_name) const
{
	for (std::vector<Location *>::size_type i = 0; i < location.size(); ++i)
		if (location[i]->get_path() == location_name)
			return location[i];
	return NULL;
}
