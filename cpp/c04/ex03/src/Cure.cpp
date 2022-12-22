/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:43:55 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 20:07:36 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
    std::cout << "Cure constructor default called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    std::cout << "Clon Cure" << std::endl;
    Cure *newCure = new Cure(*this);
    return (newCure);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals bob's wounds " << target.getName() << " * "  << std::endl; 
}

Cure::Cure(Cure const & object)
{
       std::cout << "Cure Copy Constructor " << std::endl;
        this->type = object.type;
}

Cure  &Cure::operator=(Cure const &object)
{
    std::cout << "Cure operator =" << std::endl;
    this->type = object.type;
    return (*this);
}
