/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:59:18 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/27 21:06:42 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>


int main (int argc, char **argv)
{
	std::string compare;
	std::string tmp;

	if (argc == 2)
	{
		compare = argv[1];
		for (std::string::iterator it = compare.begin(); it != compare.end() && *it != '.' ; ++it)
			tmp += *it;
	}
	if (argc  != 2 || tmp.append((".csv")) != compare)
	{
		std::cout << "Error. could not open file." << std::endl;
		return (1);
	}
	std::cout << std::setprecision(2) << std::fixed;
	BitcoinExchange data;
	data.readFile(argv[1]);
	//BBDD();
	return (0);
}
