/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:23:51 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 18:52:44 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
/*
void attack(std::string const & target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
*/

int main()
{
    FragTrap player_two("Andy");
   
    player_two.takeDamage(20);
    player_two.attack("Any");
    player_two.beRepaired(20);
    player_two.highFivesGuys();
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
