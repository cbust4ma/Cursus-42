/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:28:57 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 20:38:59 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class  DiamondTrap:public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(std::string Name);
        DiamondTrap(const DiamondTrap &n_obj); //"Copy constructor called"
        DiamondTrap  &operator=(DiamondTrap const &n_obj);
        ~DiamondTrap();
        void whoAmI(); 
        using ScavTrap::attack;
};
#endif
