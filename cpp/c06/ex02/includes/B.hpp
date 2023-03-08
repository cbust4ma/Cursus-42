/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:12 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/14 19:28:14 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

# include <exception>
# include <cstdlib>
# include <typeinfo>
# include <iostream>
# include "Base.hpp"

class B: public Base
{
	public:
		B();
		~B();
		B &operator=(B const &obj);
		B(const B &obj);
};

#endif // !B_HPP
