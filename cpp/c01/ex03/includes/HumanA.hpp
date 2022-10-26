/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:40:56 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/05 19:19:43 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H
# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		std::string name;
		//Weapon weapon;
	public:
		Weapon &weapon;
		void attack(void);
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
};

#endif
