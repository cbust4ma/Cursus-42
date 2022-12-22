/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:34:26 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 21:23:23 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : len_materia(0)
{
    for(int i = 0; i < 4 ; i++)
        _materia[i] = 0;
    std::cout << "MateriaSource Constructor Default called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    
    if(len_materia < 4 )
    {   
        _materia[len_materia] = materia;
        std::cout << "Learn materia " << _materia[len_materia]->getType() << std::endl;
        len_materia++;
        
    }
    else
        std::cout << "size materia == 4" << std::endl;
    //delete materia;
    
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    
    for(int i = 0; i < len_materia; i++)
    {
        if (_materia[i] && _materia[i]->getType().compare(type) == 0)
            return (_materia[i]->clone());
    }
    return (0);
          
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < len_materia; i++)
    {
        if (_materia[i])
            delete _materia[i];
    }
    std::cout << "Materia source Destructor calle" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
        for(int i = 0; i < 4 ; i++)
    {
        if (!_materia[i])
            *_materia[i] = *obj._materia[i];
    }
    std::cout << " MateriaSource Copy Constructor called" << std::endl;
}

MateriaSource const &MateriaSource::operator=(MateriaSource const &obj)
{
    for(int i = 0; i < 4 ; i++)
    {
        if (_materia[i])
            *_materia[i] = *obj._materia[i];
    }
    return (*this);
    std::cout << " MateriaSource Operator = " << std::endl;
    
}
