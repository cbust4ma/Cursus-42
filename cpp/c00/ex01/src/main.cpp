/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:57:22 by cbustama          #+#    #+#             */
/*   Updated: 2022/09/27 18:02:00 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void menu(std::string options, int *i, phonebook *Phonebook)
{
//	phonebook Phonebook;
//	contact contacto;

//	static int i;

//	i = 0;
//	
	//std::cout << "Introduceeee :\n SEARCH: \n ADD: \n EXIT: \n";
	//std::cin >> options;

	if (options == "SEARCH" || options == "0")
	{
		//std::cout << Phonebook._agend[i].get_firstname() << std::endl;
		//contacto.set_firstname("holaaaaaa");
		//std::cout << contacto.get_firstname() << std::endl;
		Phonebook->search();
	}
	else if (options == "ADD" || options == "1")
	{
		Phonebook->add(*i);
	//	std::cout << Phonebook->_agend[*i].get_firstname() << std::endl;
		*i += 1;
		if (*i > 7)
			*i = 0;
	}
	else if (options == "EXIT" || options == "2")
		return ;
	//else
	//	return ;
}

int main()
{
	int		i;
	std::string name;
	std::string options;
	//contact agend[8];
	phonebook Phonebook;


 	i = 0;

//	std::cout << "Introduceeee :\n SEARCH: \n ADD: \n EXIT: \n";
	while (options != "EXIT" || options != "2")
	{
		std::cout << "Introduceeee :\n [0]SEARCH: \n [1]ADD: \n [2]EXIT: \n >> ";
		//std::cin >> options;
		std::getline(std::cin, options);
		if (std::cin.eof()) 
			break;
		if (options == "EXIT" || options == "2")
			return (0);
		else if (options == "ADD"  || options == "SEARCH" || options == "0" 
				|| options == "1" || options == "2" || options == "EXIT")
			menu(options, &i ,&Phonebook);

		else
			std::cout << "ERROR\n";
	}
//	name.resize(10);
//	agend[1].set_lastname(name);
//	std::cout << agend[1].get_lastname();
//	std::cout << '|' << std::endl;
	return (0);
}
