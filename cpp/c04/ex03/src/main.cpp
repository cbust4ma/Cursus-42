/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:32:23 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/19 21:17:02 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
# include "Character.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    std::cout << " \n\n ** Primera parte *** \n" << std::endl; 
    
    ICharacter* me = new Character("me");
    
    std::cout << " \n\n ** Segunda parte *** \n" << std::endl;
     
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
   

    std::cout << " \n\n ** Tercera parte *** \n" << std::endl;
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    
    std::cout << " \n\n ** destructores *** \n" << std::endl;
    

    delete bob;
    delete me;
    delete src;
    

    return 0;
}
