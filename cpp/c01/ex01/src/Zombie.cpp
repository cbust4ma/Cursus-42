/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:13:55 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/18 19:13:58 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

void Zombie::announce()
{
    std::cout << this->_name;
    std::cout << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void)
{
    this->_name = "";
    return ;
    //std::cout << this->_name << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "███████████████████ \n";
    std::cout << this->_name << " Dead" << std::endl;
    
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
}
