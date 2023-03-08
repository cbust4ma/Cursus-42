/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:46 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/14 19:28:48 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base()
{
	//std::cout << "Constrcutor base default called\n" << std::endl;
}

Base::~Base()
{
	//std::cout << "destrcutor base called\n" << std::endl;
}

Base &Base::operator=(__attribute__((unused)) Base const &obj)
{
	//std::cout << "Base Operator Equals called" << std::endl;
	return (*this);
}

Base::Base(__attribute__((unused)) const Base &obj)
{
	//std::cout << "Copy constructor base called" << std::endl;
}
