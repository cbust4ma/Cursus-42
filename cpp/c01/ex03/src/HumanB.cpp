/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:16:28 by cbustama          #+#    #+#             */
/*   Updated: 2023/01/16 20:07:39 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->_weapon = NULL;
	std::cout << "constructor Human B called" << std::endl;
	return ;
}

HumanB::HumanB()
{
	std::cout << "constructor default Human B called" << std::endl;
	this->name = "";
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "destructor Human B called" << std::endl;
	return ;
}

void HumanB::attack(void)
{
	
	std::cout << this->name << " attack with his"  << " " ;
	if(this->_weapon != NULL)
		std::cout << this->_weapon->getType() <<  std::endl;
	else
		std::cout << "No weapon" <<  std::endl;
		
		

}

void  HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

