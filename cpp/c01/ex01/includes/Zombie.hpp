/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:14:12 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/18 19:14:15 by cbustama         ###   ########.fr       */
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
        void set_name(std::string name);
        Zombie(void);
        ~Zombie(void);
};
Zombie  *zombieHorde(int N, std::string name);
#endif
