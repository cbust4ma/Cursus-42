/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:43:55 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 20:34:39 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"


Ice::Ice()
{
    this->type = "ice";
    std::cout << "Ice constructor default called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    std::cout << "Clon Ice" << std::endl;
    Ice *newIce = new Ice(*this);
    return (newIce);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " * "  << std::endl; 
}

Ice::Ice(Ice const & object)
{
       std::cout << "Ice Copy Constructor " << std::endl;
        this->type = object.type;
}

Ice  &Ice::operator=(Ice const &object)
{
    std::cout << "Ice operator =" << std::endl;
    this->type = object.type;
    return (*this);
}
