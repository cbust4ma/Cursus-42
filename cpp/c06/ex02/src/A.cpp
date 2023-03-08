/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:33 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/14 19:28:35 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A()
{
	//std::cout << "Constrcutor A default called\n" << std::endl;
}

A::~A()
{
	//std::cout << "destrcutor A called\n" << std::endl;
}

A &A::operator=(__attribute__((unused)) A const &obj)
{
	//std::cout << "A Operator Equals called" << std::endl;
	return (*this);
}

A::A(__attribute__((unused)) const A &obj)
{
	//std::cout << "Copy constructor A called" << std::endl;
}
