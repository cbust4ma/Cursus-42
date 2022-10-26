/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:14:03 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/18 19:14:05 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string  to_char(int value)
{
    std::string tmp;
    std::string swap;

    while (value > 0)
    {
        swap = '0' + (value % 10);
        tmp = swap + tmp;
        value = value / 10;
    }
    return (tmp);
}

Zombie *zombieHorde(int N, std::string name)
{
    int     i;
    std::string tmp;
    
    i = -1;
    Zombie   *zombie = new Zombie[N];
    tmp = name;
    while (++i < N)
    { 
        name = name + ' '+ to_char(i + 1);
        zombie[i].set_name(name);
        zombie[i].announce();
        name = tmp;
    }
    return zombie;
}
