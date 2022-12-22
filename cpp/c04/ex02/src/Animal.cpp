/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:05 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/02 17:06:17 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(const Animal &n_obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    type = n_obj.type;
}

Animal &Animal::operator=(Animal const &n_obj)
{
    //std::cout << "Assignation operator called" << std::endl;
    type = n_obj.type;
    return(*this);
}

Animal::Animal()
{
    type = "NO Animal";
    std::cout << "Animal Constructor Default Called" << std::endl;
}

Animal::Animal(std::string type)
{
    this->type = type;
    std::cout << "Animal Constructor Called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}


std::string  Animal::getType() const
{
    return (this->type);
}

void Animal::setType(std::string name)
{
    type = name;
}
