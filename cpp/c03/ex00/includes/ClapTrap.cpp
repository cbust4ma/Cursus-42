/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:34:50 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/24 19:41:42 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP
# include <iostream>
# define WRITE(...) std::cout , __VA_ARGS__ , std::endl
/*The class will be called ClapTrap, and will have the following private attributes,
initialized to the specified values:
• Name (Parameter of constructor)
• Hitpoints (10)
• Energy points (10)
• Attack damage (0)
You will also give it a few public functions to make it more life-like:
• void attack(std::string const & target)
• void takeDamage(unsigned int amount)
• void beRepaired(unsigned int amount)*/
class ClapTrap
{
    private:
        int Hitpoints = 10;
        int Energypoints = 10;
        int Attackdamage = 10;
    public:
        ClapTrap();
        ClapTrap(std::string Name);
        ~ClapTrap();
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
};
#endif