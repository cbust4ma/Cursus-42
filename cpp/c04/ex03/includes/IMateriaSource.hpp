/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:47:00 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/12 22:01:51 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource();
        virtual void learnMateria(AMateria* materia) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
