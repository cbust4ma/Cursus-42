/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:42:26 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 20:32:06 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->Name = "";
    this->setaattackdamage(20);
    this->setenergy(50);
    this->sethitpoints(100);
    std::cout << "ScavTrap constructor default called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name)
{
    this->Name = Name;
    this->setaattackdamage(20);
    this->setenergy(50);
    this->sethitpoints(100);
    std::cout << "ScavTrap Constructor  called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &n_obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    Name = n_obj.Name;
    Hitpoints = n_obj.Hitpoints;
    Energypoints = n_obj.Energypoints;
    Attackdamage = n_obj.Attackdamage;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &n_obj)
{
    std::cout << "Assignation operator called" << std::endl;
    Name = n_obj.Name;
    Hitpoints = n_obj.Hitpoints;
    Energypoints = n_obj.Energypoints;
    Attackdamage = n_obj.Attackdamage;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void  ScavTrap::guardGate()
{
    std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
}
