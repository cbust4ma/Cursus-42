/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:35:11 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/21 19:35:13 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <iostream>

template <class T>
T max (T &a, T &b)
{
	return (a > b ? a : b);
}

template <class T>
T min (T &a, T &b)
{
	return (a < b ? a : b);
}

template <class T> 
void swap (T &a, T &b)
{
	T tmp(a);
	a = b;
	b = tmp;
}


#endif
