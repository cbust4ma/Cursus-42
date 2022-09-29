/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:04:20 by cbustama          #+#    #+#             */
/*   Updated: 2022/09/27 18:22:11 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone;
		std::string darkest_secret;
	//public:
		/*contact(std::string first_name, std::string last_name,
				std::string nickname, std::string phone,
				std::string darkest_secret)
		{
			this->first_name = first_name;
			this->last_name = last_name;
			this->nickname = nickname;
			this->phone = phone;
			this->darkest_secret = darkest_secret;
		}*/

	/*	~contact(void)
		{
			std::cout<<"esto se elimina" << std::endl;
			return ;
		}

		contact(void)
		{
			return ;
		}*/

	public:
		std::string get_firstname();
		void set_firstname(std::string first_name);
		std::string get_lastname();
		void set_lastname(std::string last_name);
		std::string get_nickname();
		void set_nickname(std::string nickname);
		std::string get_phone();
		void set_phone(std::string phone);
		std::string get_darksecret();
		void set_darksecret(std::string darkest_secret);
		~contact(void);
		contact(void);	
};
//void	add(contact phonebook[], int i);
#endif
