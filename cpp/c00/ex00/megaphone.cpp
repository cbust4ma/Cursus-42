/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:46:27 by cbustama          #+#    #+#             */
/*   Updated: 2022/09/28 18:36:35 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	int		i, j;
	std::string c;
	std::string out = "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	if (argc > 1)
	{
		i = 0;
		while(argv[++i])
		{
			c = argv[i], j = -1;
			while(c[++j])
				c[j] = toupper(c[j]);
			std::cout << c;
		}
		std::cout << std::endl;
	}
	else
		std::cout << out;
	return (0);
}
