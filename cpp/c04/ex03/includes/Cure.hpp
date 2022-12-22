/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:41:28 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 20:07:46 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP
# include <iostream>

# include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        AMateria* clone() const;
        Cure (Cure const & object);
        Cure  &operator=(Cure const &object);
        void use(ICharacter& target);
        Cure();
        ~Cure();
};
#endif
