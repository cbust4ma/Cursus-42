/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:42:28 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/18 16:53:16 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

/*int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	//Fixed test(14.2f);
	//Fixed test2(14.2f);
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
	cout << "max " << endl;
  	std::cout << Fixed::max( a, b ) << std::endl;
	cout << "min" << endl;
   	std::cout << Fixed::min( a, b ) << std::endl;
	//std::cout << "div" << std::endl;
	//std::cout << test2 / test << std::endl;
   
    return 0;
}*/
int	main(void)
{
	Fixed a;
	Fixed test(14.2f);
	Fixed test2(14.2f);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	cout << "hola " << endl;
	cout << b.getRawBits() << endl;
	std::cout << "div" << std::endl;
	std::cout << test2 / test << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::min(a, b) << std::endl;

	if (a > b)
		std::cout << "a is bigger than b" << std::endl;

	if (a < b)
		std::cout << "a is lower than b" << std::endl;
		
	if (test == test2)
		std::cout << "test and test2 are equals" << std::endl;
	if (a >= b)
		std::cout << " >= " << std::endl;
	if (a <= b)
		std::cout << "<=" << std::endl;
	if (a != b)
		std::cout << "!=" << std::endl;
	return (0);
}
