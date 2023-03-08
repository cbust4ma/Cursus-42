/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:06:55 by cbustama          #+#    #+#             */
/*   Updated: 2023/01/16 20:07:16 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon()
{
	std::cout << "constructor default weapon called" << std::endl;
	this->_type = "";
	return ;
}

Weapon::Weapon(std::string type)
{
	std::cout << "constructor weapon called" << std::endl;
	this->_type = type;
}

Weapon::~Weapon(void)
{
	std::cout << "Destructor weapon called" << std::endl;
	return ;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const &Weapon::getType()
{
	return (this->_type);
}
