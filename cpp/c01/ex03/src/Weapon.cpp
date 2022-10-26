/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:06:55 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/05 18:19:39 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	this->_type = "";
	return ;
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon(void)
{
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
