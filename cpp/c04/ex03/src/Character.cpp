/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:48:15 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 21:15:36 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
# include "AMateria.hpp"


Character::Character():_name("")
{
    _equip_materia = 0;
    for (int i = 0 ; i < 4 ; i++)
        _materia_character[i] = 0;
    std::cout << "Character constructor default called" << std::endl;
}

Character::Character(std::string name):_name(name)
{
    _equip_materia = 0;
    for (int i = 0 ; i < 4 ; i++)
        _materia_character[i] = 0;
    std::cout << "Character Constructor called" <<  std::endl;
}

Character::Character(Character const &obj)
{
    _name = obj._name;
    for(int i = 0; i < 4 ; i++)
    {
        if (!_materia_character[i])
            *_materia_character[i] = *obj._materia_character[i];
    }
    std::cout << " Character Copy Constructor called" << std::endl;
}
        
Character const &Character::operator=(Character const &obj)
{
    _name = obj._name;
    for(int i = 0; i < 4 ; i++)
    {
        if (_materia_character[i])
            *_materia_character[i] = *obj._materia_character[i];
    }
    std::cout << "CHaracter  operator = " << std::endl;
    return (*this);
}

Character::~Character()
{
    std::cout << "character destrcutotr called " << std::endl;
    for (int i = 0 ; i < _equip_materia ; i++)
    {
        if (_materia_character[i])
            delete _materia_character[i];
    }
    
    
}  
std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (_equip_materia < 4)
    {
        this->_materia_character[_equip_materia] = m;
         std::cout << "Equip " << this->_materia_character[_equip_materia]->getType() << std::endl;
        _equip_materia++;
    }
    else
        std::cout << "Equip is full" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    
    if(this->_materia_character[idx]->getType().compare("ice") == 0 && idx < 4)
        _materia_character[idx]->use(target);
    else if(this->_materia_character[idx]->getType().compare("cure") == 0 && idx < 4)
        _materia_character[idx]->use(target);
    else
        std::cout << "Materia no found" << std::endl; 
        
}

void Character::unequip(int idx)
{
    std::cout << "Unequip " << _materia_character[idx]->getType() << std::endl;
     _materia_character[idx] = 0;
}
