/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:58:03 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/02 18:53:31 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(const Dog &n_obj)
{
    type = n_obj.type;
    std::cout << "Copy constructor called" << std::endl;
    this->attribute = new Brain();
    *attribute = *n_obj.attribute;
    
}

Dog &Dog::operator=(Dog const &n_obj)
{
    //std::cout << "Assignation operator called" << std::endl;
    type = n_obj.type;
    return(*this);
}

Dog::Dog()
{
    attribute = new Brain();
    std::cout << "Dog Constructor Default Called" << std::endl;
}

Dog::Dog(std::string type)
{
    this->type = type;
    std::cout << "Dog Constructor Called" << std::endl;
}

Dog::~Dog()
{
    delete attribute;
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Guau Guau Guau..." << std::endl;
}

std::string  Dog::getType() const
{
    (std::string &)Animal::type = "Dog";
    return (this->type);
}
