/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:49:06 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 20:59:58 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class AMateria;

class Character: public ICharacter
{
    protected:
        std::string _name;
        AMateria *_materia_character[4];
        int _equip_materia;
    public:
        Character();
        Character(std::string _name);
        Character(Character const &obj);
        Character const &operator=(Character const &obj);
        void use(int idx, ICharacter& target);
        void equip(AMateria* m);
        virtual ~Character(); 
        void unequip(int idx);
        virtual std::string const & getName() const; 
        void prints()
        {
            std::cout << &_materia_character[0]->getType() << std::endl;
        }
};

#endif
