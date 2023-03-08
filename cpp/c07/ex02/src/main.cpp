/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:37:55 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/21 19:38:14 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 2

int main(int, char**)
{
	srand((unsigned) time(NULL));
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 10;
		std:: cout << "value -------> "<< value << "\n" << std::endl;
        numbers[i] = value;
		std::cout << "numbers -----> " << numbers[i] << "\n" <<  std::endl;
        mirror[i] = value;
		std::cout << "mirror ------> " << mirror[i] << "\n" << std::endl;
    }
	std::cout << "SIZE() ----------- " <<  numbers.size() << "-----------" << std::endl;
	
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		//std::cout << "Antes de la copia === " << tmp[0] << std::endl;
		//std::cout << "Number === " << numbers[0] << std::endl;
		/*tmp[0] = 20;
		numbers[0] = 10;
		std::cout << "Despues de la copia === " << tmp[0] << std::endl;
		std::cout << "Number === " << numbers[0] << std::endl;*/
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
			//delete [] mirror;
            return (1);
        }
		else
			 std::cerr << "save the same value!!" << std::endl;
    }

    try
    {
        numbers[-2] = 0;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand() % 10;
		std::cout << "numbers new -----> " << numbers[i] << "\n" <<  std::endl;
		std::cout << "mirror old ------> " << mirror[i] << "\n" << std::endl;

    }
    delete [] mirror;//
    return 0;
}
