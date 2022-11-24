/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:42:37 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/26 21:01:38 by cbustama         ###   ########.fr       */
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
		static const int  nbr = 8;
	public:
		Fixed();
		Fixed(const  Fixed &n_obj);
		~Fixed();
		Fixed const &operator=(Fixed &n_obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);
}
;
#endif
