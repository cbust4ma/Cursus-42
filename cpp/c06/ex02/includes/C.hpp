/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:23 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/14 19:28:25 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

# include <iostream>
# include "Base.hpp"

class C: public Base
{
	public:
		C();
		~C();
		C &operator=(C const &obj);
		C(const C &obj);
};

#endif // !C_HPP
