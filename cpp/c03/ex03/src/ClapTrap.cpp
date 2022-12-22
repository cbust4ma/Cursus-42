/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:05:40 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 20:27:01 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//ClapTrap <name> attacks <target>, causing <damage> points of damage!
/*
        int Hitpoints;
        int Energypoints;
        int Attackdamage ;*/
ClapTrap::ClapTrap():Name(""),Hitpoints(10),Energypoints(10),Attackdamage(0)
{
    std::cout << BLUE <<  "ClapTrap CONSTRUCTOR DEFAULT CALLED " << RESET <<  std::endl;
}

ClapTrap::ClapTrap(std::string Name):Name(Name),Hitpoints(10),Energypoints(10),Attackdamage(0)
{
    std::cout << BLUE << "ClapTrap CONSTRUCTOR  CALLED" << RESET << std::endl;
    
}

ClapTrap::ClapTrap(const  ClapTrap &n_obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    Name = n_obj.Name;
    Hitpoints = n_obj.Hitpoints;
    Energypoints = n_obj.Energypoints;
    Attackdamage = n_obj.Attackdamage;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &n_obj)
{
    //std::cout << "Assignation operator called" << std::endl;
    Name = n_obj.Name;
    Hitpoints = n_obj.Hitpoints;
    Energypoints = n_obj.Energypoints;
    Attackdamage = n_obj.Attackdamage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << RED <<  "ClapTrap DESRUCTOR CALLED " << this->Name << RESET << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
    std::cout <<  BOLDGREEN << "ClapTrap "  << this->Name << " attacks " << RESET << BOLDRED << target << " causing " << this->Attackdamage <<  " points of damage " << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    
    std::cout << BOLDGREEN << "ClapTrap " << this->Name << RESET << BOLDMAGENTA << " takes " << amount << " amount of damage" << RESET<<  std::endl;
     
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << BOLDBLUE << "ClapTrap " << this->Name << " has been repaired with a value of " << amount + this->Energypoints << RESET << std::endl;
}

int ClapTrap::getvalue()
{
    return (this->Hitpoints + this->Attackdamage);
}

int ClapTrap::getenergy()
{
    return (this->Energypoints);
}

void ClapTrap::setenergy(int n)
{
    this->Energypoints = n;
}

void ClapTrap::sethitpoints(int n)
{
    this->Hitpoints = n;
}

void ClapTrap::setaattackdamage(int n)
{
    this->Attackdamage = n;
}
