/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:45:40 by cbustama          #+#    #+#             */
/*   Updated: 2022/09/28 16:14:43 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	_errors(std::string tmp, std::string name)
{
	int	j;

	j = -1;
	while (!std::isalpha(tmp[++j]))
	{
		if (std::cin.eof())
			break;
		std::cin.clear();
		std::cout << "Name fail\nIntroduce " << name << std::endl;
		std::cout << name << " :";
		std::getline(std::cin, tmp);
		j--;
	}
	return tmp;
}

void	phonebook::add(int i)
{
	int	j;

	j = -1;
//	contact phonebook[8];
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string	phone;
	std::string darksecret;
	//const	int i = 0;

	std::cout << "Name : ";
	std::getline(std::cin, name);
	//std::cin>>name;
	name = _errors(name, "Name");
	_agend[i].set_firstname(name);

	/*while (!std::isalpha(name[++j]))
	{
		std::cin.clear();
		std::cout << "Name fail\nIntroduce  Name" << std::endl;
		std::cout << "Name : ";
		std::cin >> name;
		std::cout << "data" <<  name <<std::endl;
		j--;
	}*/
	//_agend[i].set_firstname(name);
	//std::cout << _agend[i].get_firstname() << std::endl;;

	std::cout << "Last name: ";
	std::getline(std::cin, last_name);
	last_name = _errors(last_name, "Last Name");
	_agend[i].set_lastname(last_name);

	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	nickname = _errors(nickname, "Nickaname");
	_agend[i].set_nickname(nickname);

	std::cout << "Phone : ";
	std::getline(std::cin, phone);
	while (!std::isdigit(phone[++j]))
	{
		if (std::cin.eof())
			break;
		std::cout << "Phone fail\n Introduce Phone" << std::endl;
		std::cout << "Phone : ";
		std::getline(std::cin, phone);
		j--;

	}
	_agend[i].set_phone(phone);

	std::cout << "Darksecret: ";
	std::getline(std::cin, darksecret);
	darksecret = _errors(darksecret, "Dark Secret");
	_agend[i].set_darksecret(darksecret);
	//i++;


}

void str_resize(std::string str)
{
	int	i;
	std::string tmp;

	i = 0;
	//std::cout << str << std::endl;
	while (i < 9)
	{
	//	tmp[i] = str[i];
		tmp += str[i];
		i++;
	}
	//std::cout << tmp << std::endl;
	tmp = tmp + '.';
	std::cout <<  std::right <<  "|" << std::setw(10) << tmp;
}
#include <string>
void	phonebook::search()
{
	int	i;
	int j;
	int	width = 10;
	std::string option;
	char complete = ' ';
	std::string s = "|";

	i = 0;
	std::cout << std::right << std::string(10*4 + 2*4, '-') << std::endl;
	std::cout << std::right << s << std::setw(width) << std::setfill(complete) << "\033[1;31m[Index]\033[0m";
	std::cout << std::right <<  s << std::setw(width) << "\033[1;31mFirst Name\033[0m";
	std::cout << std::right << s << std::setw(width) << "\033[1;31mLast  Name\033[0m";
	std::cout << std::right << s << std::setw(width) << "\033[1;31mNick  Name \033[0m" << s;
	//std::cout << std::right << s << std::setw(width) << "\033[1;31m [Phone]  \033[0m";
	//std::cout << std::right << s << std::setw(width) << "\033[1;31m [Dark Secret]  \033[0m" << s;
	std::cout << std::endl;
	std::cout << std::right << std::string(10*4 + 2*4, '-') << std::endl;
	
	while (_agend[i].get_firstname() != "" && i < 8)
	{

		std::cout << std::right << s << std::setw(10) << '[' << i << ']';
		if (_agend[i].get_firstname().length() > 9)
			str_resize(_agend[i].get_firstname());
		else
			std::cout << std::right << s << std::setw(width) << _agend[i].get_firstname();
		if (_agend[i].get_lastname().length() > 9)
			str_resize(_agend[i].get_lastname());
		else
			std::cout << std::right << s <<std::setw(width)  << _agend[i].get_lastname();
		if (_agend[i].get_nickname().length() > 9)
			str_resize(_agend[i].get_nickname());
		else
			std::cout << std::right << s << std::setw(width) << _agend[i].get_nickname() << s;
		i++;
		std::cout << std::endl;
		/*
		std::cout << std::right <<  std::string(10*4 + 2*4, '-') << std::endl;
		std::cout << "[enter [0] if you want to see a specific contact or [1] to go back. ]";
		std::cout << std::endl;
		std::cout << ">> ";
		std::cin >> option;
		if (option == 0)
			index_data(i);
		else
			return ;*/
		
	}
		std::cout << std::endl;
		std::cout << std::right <<  std::string(10*4 + 2*4, '-') << std::endl;
		std::cout << "[enter [0] if you want to see a specific contact or [1] to go back. ]";
		std::cout << std::endl;
		std::cout << ">> ";
		std::getline(std::cin, option);
		//std::cin >> option;
		j = -1;


		if (std::atoi(option.c_str()) == 0)
		{
			std::cout << "[index number [?] ]" << std::endl;
			std::cout << ">> ";
			std::getline(std::cin, option);
			while (!std::isdigit(option[++j]) || std::atoi(option.c_str()) > i)
			{
				if (std::cin.eof())
					break;
				std::cout << "[Index Fail] \nIntroduce [INDEX] " << std::endl;
				std::cout << "INDEX : ";
				std::getline(std::cin, option);
				j--;
			}
		//	std::cin >> option;
			index_data(std::atoi(option.c_str()));
		}
		//else
		//	return ;
}
