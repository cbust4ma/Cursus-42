/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:28:57 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 20:35:07 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
class  FragTrap:virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string Name);
        FragTrap(const FragTrap &n_obj); //"Copy constructor called"
        FragTrap  &operator=(FragTrap const &n_obj);
        ~FragTrap();
         void highFivesGuys();
};
#endif
