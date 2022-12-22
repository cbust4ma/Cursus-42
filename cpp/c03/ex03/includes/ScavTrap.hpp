/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:28:57 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 20:31:29 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
class  ScavTrap:virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string Name);
        ScavTrap(const ScavTrap &n_obj); //"Copy constructor called"
        ScavTrap  &operator=(ScavTrap const &n_obj);
        ~ScavTrap();
        void guardGate();
};
#endif
