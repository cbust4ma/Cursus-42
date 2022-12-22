/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:50:08 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/01 19:44:05 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat:public Animal
{
    private:
        Brain *attribute;
    public:
        Cat();
        Cat(std::string type);
        Cat(const  Cat &n_obj); //"Copy constructor called"
        Cat  &operator=(Cat const &n_obj);
        void makeSound() const;
        std::string getType()const;
         ~Cat();
};
#endif
