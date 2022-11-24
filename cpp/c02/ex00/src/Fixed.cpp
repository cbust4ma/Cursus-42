/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:42:23 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/26 21:01:41 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixed(0)
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const  Fixed &n_obj)
{
    cout << "Copy constructor called" << endl;
    _fixed = n_obj._fixed;
}

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;   
}

Fixed const &Fixed::operator=(Fixed &n_obj)
{
    cout << "Assignation operator called" << endl;
    _fixed = n_obj._fixed;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    cout << "getRawBits member function called" << endl;
    return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
    cout << "setRawBits member function called" << endl;
    this->_fixed = raw;
}
