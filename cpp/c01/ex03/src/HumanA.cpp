/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:11:18 by cbustama          #+#    #+#             */
/*   Updated: 2023/01/16 20:07:49 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):weapon(weapon)
{
	std::cout << "constructor Human A called" << std::endl;
	this->name = name;
	//Weappn::weapon = &weapon;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "destructor Human A called" << std::endl;
	return ;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attack with his" << " " << this->weapon.getType() << std::endl;

}

