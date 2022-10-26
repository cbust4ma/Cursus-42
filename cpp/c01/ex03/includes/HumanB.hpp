/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:52:05 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/05 19:18:11 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
		std::string name;
		
	public:
		Weapon *_weapon;
		void attack(void);
		HumanB(std::string name);
		HumanB();
		~HumanB(void);
		void setWeapon(Weapon &weapon);
};

#endif
