/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:09:24 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/04 19:38:11 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string var = "HI THIS IS BRAIN";
	std::string stringPTR;
	std::string *stringREF;

	stringPTR = var;
	stringREF = &var;
	std::cout << "Direccion de memoria var [&] : " << &var << std::endl;
	std::cout << "Direccion de memoria stringPTR [&] : " << &stringPTR << std::endl;
	std::cout << "Direccion de memoria stringREF [&] : " << stringREF << std::endl;
	std::cout << "puntero var [*] : " << var << std::endl;
	std::cout << "puntero StringREF [*] : " << *stringREF << std::endl;
	std::cout << "puntero stringPTR [*] : " << stringPTR << std::endl;
	return (0);
}
