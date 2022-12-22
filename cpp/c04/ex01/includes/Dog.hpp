/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:56:00 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/01 14:16:29 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog:public Animal
{
    private:
        Brain *attribute;
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
