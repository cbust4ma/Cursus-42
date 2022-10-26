/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:14:44 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/18 19:14:45 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

void    create_zombie()
{
    Zombie zombie_one(getenv("USER"));
    Zombie *zombie_two = newZombie("Zombie_two");
    zombie_one.announce();
    zombie_two->announce();
    randomChump("Zombie_three");
    delete zombie_two;
}

int  main(void) 
{
    return (create_zombie(), 0);
}
