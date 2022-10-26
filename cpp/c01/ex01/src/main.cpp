/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:13:46 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/18 19:13:51 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

void    create_zombie(int N, std::string name)
{
 
    Zombie *zombie = zombieHorde(N, name);
    delete[] zombie;
    
}

int  main(int argc, char *argv[]) 
{
    if(argc != 2 || atoi(argv[1]) < 0)
        std::cout << "[ERROR]\n";
    else
        create_zombie(atoi(argv[1]), "[|hola|]");
    return (0);
}
