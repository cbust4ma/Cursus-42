/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:05:07 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 20:25:34 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

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
    protected:
        std::string Name;
        int Hitpoints;
        int Energypoints;
        int Attackdamage ;
    public:
        ClapTrap();
        ClapTrap(std::string Name);
        ClapTrap(const ClapTrap &n_obj); //"Copy constructor called"
        ClapTrap  &operator=(ClapTrap const &n_obj);
        ~ClapTrap();
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int  getvalue();
        int  getenergy();
        void setenergy(int n);
        void sethitpoints(int n);
        void setaattackdamage(int n);
        
};
#endif
