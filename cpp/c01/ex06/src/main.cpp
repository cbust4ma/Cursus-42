/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:36:04 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/21 21:30:58 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "karen.hpp"

int main (int argc, char **argv)
{
	karen Karen;
	if (argc == 2)
		Karen.complain(argv[1]);
	else
		cout << "Only One parameter [DEBUG] [INFO] [ERROR] [WARNING]" << endl;
	return (0);
}
