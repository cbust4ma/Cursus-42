/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:39 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/14 19:28:41 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B()
{
	//std::cout << "Constrcutor B default called\n" << std::endl;
}

B::~B()
{
	//std::cout << "destrcutor B called\n" << std::endl;
}

B &B::operator=(__attribute__((unused)) B const &obj)
{
	//std::cout << "B Operator Equals called" << std::endl;
	return (*this);
}

B::B(__attribute__((unused)) const B &obj)
{
	//std::cout << "Copy constructor B called" << std::endl;
}
