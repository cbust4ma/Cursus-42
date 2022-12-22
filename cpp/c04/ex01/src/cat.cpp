/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:52:06 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/01 19:59:51 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(const Cat &n_obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    type = n_obj.type;
    //copy constructor guardando el valor realmente llamando al operador de igualdad 
    this->attribute = new Brain();
    *attribute = *n_obj.attribute;
}

Cat &Cat::operator=(Cat const &n_obj)
{
    //std::cout << "Assignation operator called" << std::endl;
    
    attribute = n_obj.attribute;
    return (*this);
}

Cat::Cat()
{
    attribute =  new Brain();
    std::cout << "Cat Constructor Default Called" << std::endl;
}

Cat::Cat(std::string type)
{
    this->type = type;
    std::cout << "Cat Constructor Called" << std::endl;
}

Cat::~Cat()
{
    delete attribute;
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miau Miau Miau..." << std::endl;
}

std::string  Cat::getType() const
{
    (std::string &)Animal::type = "Cat";
    return (this->type);
}
