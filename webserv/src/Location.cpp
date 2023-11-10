# include "Location.hpp"
# include "Config.hpp"

Location::Location()
{}

Location::Location(std::string file_name)
{
	this->file = file_name;
	location = init_location_route();
	this->file = extract_info_of_location();
	init_allowed_methods();
	init_autoindex();
	this->upload = extract_string_param_info("upload");
	this->redirect = extract_string_param_info("redirect");
	if (redirect.substr(0, 7) != "http://" && redirect.length() != 0)
	{
		redirect = "http://" + redirect;
	}
	this->index = "index.html";
	if (extract_string_param_info("index") != "")
		this->index = extract_string_param_info("index");
	init_allowed_cgi();
}

Location::~Location()
{}

Location::Location(const Location &obj)
{
	*this = obj;

	return;	
}

Location	&Location::operator=(const Location &obj) {

	this->location = obj.location;
	this->file = obj.file;
	this->index = obj.index;
	this->upload = obj.upload;
	this->redirect = obj.redirect;
	this->GET = obj.GET;
	this->POST = obj.POST;
	this->DELETE = obj.DELETE;
	this->autoindex = obj.autoindex;
	this->redirect_bool = obj.redirect_bool;

	for (std::map<std::string, bool>::const_iterator it = obj.cgi_ext.begin(); it != obj.cgi_ext.end(); ++it)
		cgi_ext[it->first] = it->second;

	return *this;
}

std::string		Location::init_location_route()
{
	std::istringstream iss(this->file);
    std::string token;

    while (iss  >> token)
	{
		if (token == "location") {
            iss >> token;
			if (token[token.size() - 1] == '/' && token.size() != 1)
				token = token.substr(0, token.size() - 1);
			break;
        }
    }
    return token;
}

void		Location::init_autoindex()
{  
	size_t start;
	size_t end;
	std::string line;
	std::string answ;
	std::string param;	
	std::string token;

	autoindex = false;
	start = 0;
	param = "autoindex";
	end = this->file.find(';');
	while (file.find(";", start) != std::string::npos)
	{
		line =  file.substr(start, end - start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		if (param == line.substr(0, param.length()))
		{
			if (line[line.length()-1] == ';')
			line.erase(line.end() - 1);
			std::istringstream iss(line);
			iss  >> token >> token;
			std::string value = token;
			if (value == "on")
				autoindex = true;
			break;
		}
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}
}

void		Location::init_redirection()
{  
	size_t start;
	size_t end;
	std::string line;
	std::string answ;
	std::string param;
	std::string token;

	start = 0;
	param = "redirect";
	end = this->file.find(';');
	while (file.find(";", start) != std::string::npos)
	{
		line =  file.substr(start, end - start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		if (param == line.substr(0, param.length()))
		{
			line.erase(line.end() - 1);
			std::istringstream iss(line);
			iss  >> token >> token;
			redirect = token;
			break;
		}
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}
}

void	Location::init_allowed_methods()
{
	size_t start;
	size_t end;
	std::string line;
	std::string answ;
	std::string param;
	std::string token;

	GET = false;
	POST = false;
	DELETE = false; 
	start = 0;
	param = "methods";
	end = this->file.find(';');
	while (file.find(";", start) != std::string::npos)
	{
		line =  file.substr(start, end - start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		line.erase(line.end() - 1);
		if (param == line.substr(0, param.length()))
		{
			std::istringstream iss(line);
			while (iss  >> token)
			{
				if (token == "GET")
					GET = true;
				if(token == "POST") 
					POST = true;
				if(token == "DELETE")
					DELETE = true;
    		}
			break;

		}
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}
}

void	Location::init_allowed_cgi()
{
	size_t start;
	size_t end;
	std::string line;
	std::string answ;
	std::string param;
	std::string token;

	cgi_ext.insert(std::make_pair("py", false));
	cgi_ext.insert(std::make_pair("sh", false));
	start = 0;
	param = "cgi_ext";
	end = this->file.find(';');
	while (file.find(";", start) != std::string::npos)
	{
		line =  file.substr(start, end - start);
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		line.erase(line.end() - 1);
		if (param == line.substr(0, param.length()))
		{
			std::istringstream iss(line);
			while (iss  >> token)
			{
				std::map<std::string, bool>::iterator it;
    			for (it = cgi_ext.begin(); it != cgi_ext.end(); ++it)
				{
    			    if (it->first == token)
						it->second = true;
    			}
    		}
			break;

		}
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}
}

std::string	Location::extract_info_of_location()
{
	size_t start;
	std::string::iterator it;
	int end;
	

	start = this->file.find("{") + 1;
	it = this->file.begin() + start;
	end = 0;
	while (it != this->file.end()) 
	{
		if (*it == '}')
		{
			end = std::distance(this->file.begin(), it);
			break ;
		}
		it++;
    }
	return this->file.substr(start, end - start);
}

int Location::extract_int_param_info(std::string param)
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
		start = end + 1;
		end = this->file.find(';', start) + 1;
	}

	if (is_numeric(answ) && answ != "")
		return std::stoi(answ);
	return (-1);
}

std::string Location::extract_string_param_info(std::string param)
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

std::string Location::get_path() const
{
	return location;
}

std::string Location::get_upload() const
{
	return upload;
}

bool		Location::get_post() const
{
	return POST;
}

bool		Location::get_delete() const
{
	return DELETE;
}

bool		Location::get_get() const
{
	return GET;
}

std::string Location::get_index() const
{
	return index;
}
std::string Location::get_redirect() const
{
	return redirect;
}
bool Location::get_autoindex() const
{
	return autoindex;
}

void Location::set_path(std::string path)
{
	this->location = path;
}

void Location::set_get(bool get)
{
	this->GET = get;
}

void Location::set_post(bool post)
{
	this->POST = post;
}

void Location::set_delete(bool dele)
{
	this->DELETE = dele;
}

void Location::set_index(std::string index)
{
	this->index = index;
}

void Location::set_autoindex(bool index)
{
	this->autoindex = index;
}

void Location::set_redirectBool(bool redirect)
{
	this->redirect_bool = redirect;
}

std::map<std::string, bool> Location::get_cgi_ext()
{
	return cgi_ext;
}



bool Location::get_cgi_ext_value(std::string ext)
{
	if (cgi_ext.count(ext))
		return cgi_ext[ext];
	return false;
}
