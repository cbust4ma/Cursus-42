# include <iostream>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <cstring>
# include <stdlib.h>
# include <sstream>
# include <map>
# include <vector>
# include <iterator>

# include <fstream>
# include <sys/event.h>
# include <netdb.h>
# include <fcntl.h>
# include <string>

#ifndef LOCATION_HPP
#define LOCATION_HPP

class Location
{
	private:
		std::string 				location;
		std::string 				file;
		bool						GET;
		bool						POST;
		bool						DELETE;
		bool						autoindex;
		bool						redirect_bool;
		
		std::string					index;
		std::string					upload;
		std::string					redirect;
		std::map<std::string, bool> cgi_ext;

		std::string					init_location_route();
		void						init_allowed_methods();
		void						init_allowed_cgi();
		std::string					extract_info_of_location();
		int							extract_int_param_info(std::string param);
		std::string					extract_string_param_info(std::string param);
		void						init_autoindex();
		void						init_redirection();

	public:
		Location();
		Location(std::string file_name);
		~Location();
		Location(const Location &obj);
		Location	&operator=(const Location &obj);

		std::map<std::string, bool> get_cgi_ext();
		std::string 				get_path() const;
		std::string 				get_index() const;
		std::string 				get_redirect() const;
		std::string 				get_alias() const;
		std::string 				get_upload() const;
		bool						get_cgi_ext_value(std::string ext);
		bool						get_post() const;
		bool						get_delete() const;
		bool						get_get() const;
		bool						get_autoindex() const;

		void 						set_autoindex(bool index);
		void 						set_redirectBool(bool redirect);
		void 						set_path(std::string path);
		void 						set_get(bool get);
		void 						set_post(bool post);
		void 						set_delete(bool dele);
		void 						set_index(std::string index);
};


#endif
