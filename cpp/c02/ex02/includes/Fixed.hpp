/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:42:37 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/16 16:57:06 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

class Fixed
{
	private:
		int _fixed;
		static const int  _nbr = 8;
	public:
		Fixed();
		Fixed(int const nbr);
		Fixed(float const nbr);
		Fixed(const  Fixed &n_obj);
		~Fixed();
		Fixed  &operator=(Fixed const &n_obj);
		/*Six comparison operators  >, <, >=, <=, == y !=. */
		int  operator>(Fixed const &n_obj);
		int  operator<(Fixed const &n_obj);
		int  operator>=(Fixed const &n_obj);
		int  operator<=(Fixed const &n_obj);
		int  operator==(Fixed const &n_obj);
		int  operator!=(Fixed const &n_obj);


		/*Four arithmetic operators: +, -, *, and /.*/
		Fixed  operator+(Fixed const &n_obj);
		Fixed  operator-(Fixed const &n_obj);
		Fixed  operator*(Fixed const &n_obj);
		Fixed operator/(Fixed const &n_obj);
		/*increment*/
		Fixed  operator++(void);
		Fixed operator++(int);
		Fixed  operator--(void);
		Fixed operator--(int);
		static Fixed max(Fixed const &a, Fixed const &b);
		static Fixed min(Fixed const &a, Fixed const &b);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
};
std::ostream& operator<<(std::ostream& call_obj, const Fixed& obj);
#endif
