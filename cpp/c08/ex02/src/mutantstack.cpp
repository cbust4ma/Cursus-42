/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:57:33 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/06 19:53:48 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <type_traits>

template <typename T>
MutantStack<T>::MutantStack(){}
template <typename T>
MutantStack<T>::~MutantStack(){}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy_obj)
{
    if (copy_obj.empty())
        std::cout << "emty" << std::endl;
    else
        std::cout << "no is empty" << std::endl;
    if (*this != copy_obj)
        *this = copy_obj;

}

/*template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &n_obj)
{
    if (*this == n_obj)
        std::cout << "no empty" << std::endl;
    if (*this != n_obj)
        std::cout << "no empty 2" << std::endl;  
    return (*this);
}
*/
