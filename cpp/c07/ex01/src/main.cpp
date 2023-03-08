/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:36:05 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/21 19:36:07 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

//std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x )
{ 
	std::cout << x << std::endl; return; 
}

template< typename T >

void fibo(T const & x)
{
	std::size_t	aux;
	std::size_t	fib;

	aux = 1;
	fib = 0;

	for(int cont = 1; cont <= x; cont++)
	{
      std::cout << "[" << fib << "] ";
      aux += fib;
      fib = aux - fib;
    }

	std::cout << std::endl;

}

int main() 
{
	int tab[] = { 0, 1, 2, 3, 4 };

	std::string arr[] = {"Uno", "Dos", "Tres", "Cuatro", "Cinco"};

	Awesome tab2[5];

	iter( arr, 5, print);
	iter( tab, 5, fibo);

	iter( tab, 5, print );

	iter( tab2, 5, print );

	
	return (0);
}

