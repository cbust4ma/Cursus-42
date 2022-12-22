/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:56:24 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 19:30:01 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const & type);
        AMateria();
        virtual ~AMateria();
        AMateria(AMateria const &object);
        AMateria &operator=(AMateria const &object);
        std::string const & getType() const; //Returns the materia type
        void setType(std::string name);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
#endif
