/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:52:06 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/30 12:54:27 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(const WrongCat &n_obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    type = n_obj.type;
}

WrongCat &WrongCat::operator=(WrongCat const &n_obj)
{
    //std::cout << "Assignation operator called" << std::endl;
    type = n_obj.type;
    return (*this);
}

WrongCat::WrongCat()
{
    std::cout << "WrongCat Constructor Default Called" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    this->type = type;
    std::cout << "WrongCat Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Miau Miau Miau..." << std::endl;
}

std::string  WrongCat::getType() const
{
    return (this->type);
}
