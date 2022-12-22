/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:43:55 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/01 19:40:15 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const  Animal &n_obj); //"Copy constructor called"
        Animal  &operator=(Animal const &n_obj);
        virtual void makeSound() const;
        virtual ~Animal();
        virtual std::string getType()const;
        void setType(std::string name);

};
#endif
