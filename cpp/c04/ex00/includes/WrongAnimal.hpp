/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:43:55 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/30 12:37:27 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const  WrongAnimal &n_obj); //"Copy constructor called"
        WrongAnimal  &operator=(WrongAnimal const &n_obj);
        void makeSound() const;
        ~WrongAnimal();
        std::string getType()const;

};
#endif
