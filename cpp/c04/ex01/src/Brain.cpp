/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:57:54 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/01 19:46:04 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Copy Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &d_copy)
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = d_copy.ideas[i];
    std::cout << "Copy constructor DEEP called" << std::endl;
}

Brain &Brain::operator=(const Brain &d_copy)
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = d_copy.ideas[i];
    return(*this);
    std::cout << "Brain Copy operator equals called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}
