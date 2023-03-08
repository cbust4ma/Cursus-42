/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:18 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/14 19:28:20 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>

class Base
{
	public:
		Base();
		virtual ~Base();
		Base &operator=(Base const &obj);
		Base(const Base &obj);
};

#endif // !BASE_HPP
