/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:00:28 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/01 19:57:17 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    int len = 2;
    Animal *arr[10];
    for(int count = 0; count < len; count++)
    {
        if(count % 2 == 0)
             arr[count] = new Dog();
        else
            arr[count] = new Cat();
    }
    
    {
        std::cout << "COPY TEST\n";
        Dog c1;
        Dog c2(c1);
        std::cout << "COPY TEST END\n";
    }
    //should not create a leak
    for(int i = 0; i < len; i++)
         delete arr[i];
}
