/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:14:35 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/18 19:14:37 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ZOMBIE_H
# define ZOMBIE_H
#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        void    announce(void);
        Zombie(std::string name);
        ~Zombie(void);
};

Zombie *newZombie (std::string name);
void    randomChump(std::string name);

#endif
