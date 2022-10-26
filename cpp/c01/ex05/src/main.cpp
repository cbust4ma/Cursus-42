/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:36:04 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/21 21:25:02 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "karen.hpp"

int main ()
{
	karen Karen;
	Karen.complain("DEBUG");
	Karen.complain("INFO");
	Karen.complain("ERROR");
	Karen.complain("WARNING");
	Karen.complain("TESTME");
	return (0);
}
