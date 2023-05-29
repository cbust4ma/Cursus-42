/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:23:47 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/29 20:09:10 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>
#include <stdexcept>


PmergeMe::PmergeMe()
:_deque(), _vector()
{
	
}

PmergeMe::PmergeMe(const PmergeMe &copy):_deque(), _vector()
{
	this->_vector = copy._vector;
	this->_deque = copy._deque;
}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	this->_vector = copy._vector;
	this->_deque = copy._deque;
	return (*this);
}


int PmergeMe::parser_arguments(char **s)
{
    //int n;
    
    std::string::iterator it;
    for (int i = 0; s[i] ; i++)
    {
        std::string str = s[i];
        for (it = str.begin(); it != str.end(); ++it)
        {
			try
			{
				PmergeMe::push_back_checked(_vector, str);
                PmergeMe::push_back_checked(_deque, str);
			}
            catch(std::exception &e)
			{
				throw std::invalid_argument(e.what());
				return (-1);
			}
                //data.push_back(n);;
        }
        
    }  
    std::vector<int>::iterator iter = _vector.begin() + 1;
    while (iter != _vector.end())
    {
        if (*iter < *(iter - 1))
            break ;
        iter++;
    }
    if (iter == _vector.end())
        return (1);
// Imprimir tiempo con decimales

   
    //for (std::vector<int>::iterator it = _vector.begin() ; it != _vector.end(); ++it)
      //  std::cout << *it << " ";
	//std::cout << std::endl;
return (0);
}

std::vector<int>& PmergeMe::getVector() 
{ 
    return this->_vector; 
}
std::deque<int>& PmergeMe::getDeque() 
{ 
    return this->_deque;
}
