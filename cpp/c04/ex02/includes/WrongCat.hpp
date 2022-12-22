/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:50:08 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/30 12:52:54 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat:public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const  WrongCat &n_obj); //"Copy constructor called"
        WrongCat  &operator=(WrongCat const &n_obj);
        void makeSound() const;
        std::string getType()const;
        ~WrongCat();
};
#endif
