/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:42:26 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 20:37:03 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->Name = "";
    this->setaattackdamage(30);
    this->setenergy(100);
    this->sethitpoints(100);
    std::cout << "FragTrap constructor default called" << std::endl;
}

FragTrap::FragTrap(std::string Name)
{
    this->Name = Name;
    this->setaattackdamage(30);
    this->setenergy(100);
    this->sethitpoints(100);
    std::cout << "FragTrap Constructor  called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &n_obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    Name = n_obj.Name;
    Hitpoints = n_obj.Hitpoints;
    Energypoints = n_obj.Energypoints;
    Attackdamage = n_obj.Attackdamage;
}

FragTrap &FragTrap::operator=(FragTrap const &n_obj)
{
    std::cout << "Assignation operator called" << std::endl;
    Name = n_obj.Name;
    Hitpoints = n_obj.Hitpoints;
    Energypoints = n_obj.Energypoints;
    Attackdamage = n_obj.Attackdamage;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void  FragTrap::highFivesGuys()
{
    std::cout << "FragTrap high fives request." << std::endl;
}
