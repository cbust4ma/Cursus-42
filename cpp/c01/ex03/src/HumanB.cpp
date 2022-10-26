/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:16:28 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/05 19:22:23 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->_weapon = NULL;
	return ;
}

HumanB::HumanB()
{
	this->name = "";
	return ;
}

HumanB::~HumanB(void)
{
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

