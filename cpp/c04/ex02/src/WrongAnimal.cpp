/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:05 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/30 12:54:16 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const WrongAnimal &n_obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    type = n_obj.type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &n_obj)
{
    //std::cout << "Assignation operator called" << std::endl;
    type = n_obj.type;
    return(*this);
}

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor Default Called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    this->type = type;
    std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound ..... " << std::endl;
}

std::string  WrongAnimal::getType() const
{
    return (this->type);
}
