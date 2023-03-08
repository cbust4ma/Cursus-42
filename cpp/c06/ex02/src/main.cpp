/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:59 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/14 19:29:01 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <sstream>

Base *generate(void)
{
	int n_random;
	Base *base;

	srand((unsigned) time(NULL));
	n_random = rand() % 3;

	if (n_random == 0)
		base = new C();
	else if (n_random == 1)
		base = new A();
	else
		base = new B();
	return (base);
}

void identify(Base &p)
{
	std::cout << "<------ Is reference ------>\n" << std::endl;
	try
	{
		

		std::ostringstream a;
		a << &p;
		std::string tmp = a.str();
		//std::cout << tmp << std::endl;
		if (tmp == "0x0")
			throw std::bad_cast();
	}
	catch (const std::exception &e)
	{
		std::cerr << "NULL Ref\n" << e.what() << std::endl;
		return ;
	}
	try
	{
		C tmp;
		tmp = dynamic_cast<C &>(p);
		std::cout << "Is C\n" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "No is C\n" << e.what() << std::endl;
	}

	try
	{
		B tmp;
		tmp = dynamic_cast<B &>(p);
		std::cout << "Is B\n" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "No Is B\n" << e.what() << std::endl;
	}
	try
	{
		A tmp;
		tmp = dynamic_cast<A &>(p);
		std::cout << "Is A\n" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "No Is A\n" << e.what() << std::endl;
	}
}

void identify(Base *p)
{
	std::cout << "<------- Is pointer----->\n" << std::endl;
	if(dynamic_cast<A *>(p))
		std::cout << "A\n" << std::endl;
	else
		std::cout << "No is A\n" << std::endl;
	if(dynamic_cast<B *>(p))
		std::cout << "B\n" << std::endl;
	else
		std::cout << "No is B\n" << std::endl;
	if(dynamic_cast<C *>(p))
		std::cout << "C\n" << std::endl;
	else
		std::cout << "No is C\n" << std::endl;
	if (p == NULL)
		std::cout << "Is Null pointer" << std::endl;
}

int main ()
{
	Base *instance;
	Base *novalid = NULL;
	
	instance = generate();

	identify(instance);
	std::cout << std::endl;
	identify(novalid);
	std::cout << std::endl;
	identify(*instance);
	std::cout << std::endl;
	identify(*novalid);
	//std::cout << std::endl;

	delete instance;
	return (0);
}
