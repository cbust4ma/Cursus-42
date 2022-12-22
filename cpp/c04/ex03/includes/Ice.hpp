/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:41:28 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 20:09:11 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>

# include "AMateria.hpp"


class Ice: public AMateria
{
    public:
        AMateria* clone() const;
        Ice (Ice const & object);
        Ice  &operator=(Ice const &object);
        void use(ICharacter& target);
        Ice();
        ~Ice();
};
#endif
