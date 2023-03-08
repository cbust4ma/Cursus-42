/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:53 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/14 19:28:55 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C()
{
	//std::cout << "Constrcutor C default called\n" << std::endl;
}

C::~C()
{
	//std::cout << "destrcutor C called\n" << std::endl;
}

C &C::operator=(__attribute__((unused)) C const &obj)
{
	//std::cout << "C Operator Equals called" << std::endl;
	return (*this);
}

C::C(__attribute__((unused)) const C &obj)
{
	//std::cout << "Copy constructor C called" << std::endl;
}
