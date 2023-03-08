/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:35:56 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/21 19:35:58 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T *arr, int longarr, void (* func)(T const &))
{
	for (int iterator = 0; iterator < longarr ; iterator++)
		func(arr[iterator]);
}

#endif
