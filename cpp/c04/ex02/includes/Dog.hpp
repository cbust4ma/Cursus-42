/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:56:00 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/30 13:06:01 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog:public Animal
{
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &n_obj); //"Copy constructor called"
        Dog  &operator=(Dog const &n_obj);
        void makeSound() const;
        std::string getType()const;
        ~Dog();
};
#endif
