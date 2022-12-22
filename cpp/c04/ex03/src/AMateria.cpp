/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:22:49 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 20:25:59 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria():type("none")
{
    
    std::cout << "Amateria Constructor default called" << std::endl;
}

AMateria::AMateria(std::string const &type)

{
    this->type = type;
    std::cout << "Constructo called" << std::endl;
           
}

AMateria::AMateria(AMateria const &object)
{
   // this->type = new AMateria();
   std::cout << "Amateria Copy Constructor " << std::endl;
    type = object.type;
    
}

AMateria::~AMateria()
{
    std::cout << "Amateria Destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &object)
{
    std::cout << "Amateria operator =" << std::endl;
    this->type = object.type;
    return (*this);
}

std::string const &AMateria::getType() const //Returns the materia type
{
    return(this->type);
}

void AMateria::setType(std::string name)
{
    this->type = name;
}
//virtual void use(ICharacter& target);

void AMateria::use(ICharacter& target)
{
    std::cout << "* Use " << target.getName() << " * "  << std::endl; 
}
