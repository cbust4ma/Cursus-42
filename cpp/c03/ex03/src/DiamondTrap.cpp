/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:42:26 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 20:40:00 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
• Name (Parameter of constructor)
• Claptrap::Name (Parameter of constructor + "_clap_name")
• Hitpoints (Fragtrap)
• Energy points (Scavtrap)
• Attack damage (Fragtrap)
• attack (Scavtrap)
It will have the special functions of both.
*/
DiamondTrap::DiamondTrap():ScavTrap(), FragTrap()
{
    this->name = "";
    std::cout << "DiamondTrap constructor default called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name):ScavTrap(Name), FragTrap(Name)
{
    this->name = Name;
    ClapTrap::Name = Name + "_clap_name";
    this->Energypoints = 50;
    std::cout << "Diamond Constructor  called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &n_obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    Name = n_obj.Name;
    Hitpoints = n_obj.Hitpoints;
    Energypoints = n_obj.Energypoints;
    Attackdamage = n_obj.Attackdamage;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &n_obj)
{
    std::cout << "Assignation operator called" << std::endl;
    Name = n_obj.Name;
    Hitpoints = n_obj.Hitpoints;
    Energypoints = n_obj.Energypoints;
    Attackdamage = n_obj.Attackdamage;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond  Destructor called" << std::endl;
}

void  DiamondTrap::whoAmI()
{
    std::cout << "Diamond Name: " << this->name << std::endl;
    std::cout << "ClapTrap Name: " << ClapTrap::Name << std::endl;
}
