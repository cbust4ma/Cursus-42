/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:32:08 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/21 21:18:20 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "karen.hpp"
#include <string>

void	karen::debug()
{
	cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!." << endl;
}

void	karen::info()
{
	cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << endl;
}

void	karen::warning()
{
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.." << endl;
}

void	karen::error()
{
	cout << "This is unacceptable, I want to speak to the manager now.." << endl;
}

static int _indexof(string arr[], string string_pos, int size_array)
{
	int index = 0;
	while (index < size_array && arr[index] != string_pos)
		index++;
	return (index == size_array ? -1 : index);
}

void	karen::complain(string level)
{
	void	(karen::*callme[4])(void) = {&karen::debug, &karen::info, &karen::warning, &karen::error};
	string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	cout << level << "\n";
	if (_indexof(arr, level, 4) != -1)
		(this->*callme[_indexof(arr, level, 4)])();
}
