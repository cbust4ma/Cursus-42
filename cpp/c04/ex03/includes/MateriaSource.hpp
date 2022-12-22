/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:32:13 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 21:18:48 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "Ice.hpp"

class MateriaSource: public IMateriaSource
{
    protected:
        AMateria *_materia[4];
        int len_materia;
    public:
        MateriaSource();
        MateriaSource(MateriaSource const &obj);
        MateriaSource const &operator=(MateriaSource const &obj);
        void learnMateria(AMateria* materia);
        virtual ~MateriaSource();
        AMateria* createMateria(std::string const & type);  
};

#endif
