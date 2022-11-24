/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:42:23 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/15 20:49:00 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

float Fixed::toFloat(void) const
{ 
  
    return (roundf(_fixed) / (1 << _nbr));   
}

int Fixed::toInt(void) const
{     
    return (_fixed / (1 << _nbr));   
}

std::ostream& operator<<(std::ostream& call_obj, const Fixed &obj)
{
    float n;
 
    n = obj.toFloat();
    //n = obj.getRawBits();
    call_obj << n;
    
    return call_obj;
}

Fixed::Fixed():_fixed(0)
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const  Fixed &n_obj)
{
    cout << "Copy constructor called" << endl;
    _fixed = n_obj._fixed;
}

Fixed::Fixed(int const nbr)
{
    cout << "Int constructor called" << endl;
    this->_fixed = (nbr * (1 << _nbr));
}

Fixed::Fixed(float const nbr)
{
    cout << "Float constructor called" << endl;
    //this->_fixed = (double)nbr;
    this->_fixed = roundf((nbr * (1 << _nbr)));
    //this->_fixed = nbr << 8;
}

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;   
}

Fixed &Fixed::operator=(Fixed const &n_obj)
{
    cout << "Assignation operator called" << endl;
    _fixed = n_obj._fixed;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    //cout << "getRawBits member function called" << endl;
    return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
    cout << "setRawBits member function called" << endl;
    this->_fixed = raw;
}
