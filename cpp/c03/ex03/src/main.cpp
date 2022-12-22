/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:23:51 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 18:54:29 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
/*
void attack(std::string const & target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
*/

int main()
{
    DiamondTrap player_three("Andy");
    //player_three.takeDamage(4);
    
    player_three.attack("Nyahhh");
    player_three.takeDamage(15);
    player_three.beRepaired(10);
    player_three.whoAmI();
    /*FragTrap player_two("Andy");
   
    player_two.takeDamage(20);
    player_two.attack("Any");
    player_two.beRepaired(20);
    player_two.highFivesGuys();*/
   /*ScavTrap player_two("Andy");
   
    player_two.takeDamage(20);
    player_two.attack("Any");
    player_two.beRepaired(20);
    player_two.guardGate();*/
    /*ClapTrap player("Andy");
    player.takeDamage(15);
    player.attack("Any");
    player.beRepaired(15);*/

}
