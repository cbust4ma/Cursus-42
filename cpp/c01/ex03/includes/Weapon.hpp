/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:54:04 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/05 18:26:54 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
//# include "HumanA.hpp"
//# include "HumanB.hpp"
# include <string>

class Weapon
{
	private:
		std::string _type;
	public:
		std::string const &getType();
		Weapon(std::string const type);
		Weapon();
		~Weapon(void);
		void setType(std::string type);
};

#endif
