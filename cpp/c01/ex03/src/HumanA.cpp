/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:11:18 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/05 19:15:38 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):weapon(weapon)
{
	this->name = name;
	//Weappn::weapon = &weapon;
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attack with his" << " " << this->weapon.getType() << std::endl;

}

