/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:37:22 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/12 21:32:05 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource()
{

    std::cout << "ImateriaSource Destructor called" << std::endl;  
}
//virtual AMateria* createMateria(std::string const & type) = 0;
