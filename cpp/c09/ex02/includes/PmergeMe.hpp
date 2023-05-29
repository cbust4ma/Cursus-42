/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:14:13 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/29 19:48:37 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP
 #include <iostream>

 #include <vector>
 #include <string>
 #include <stdexcept>
 #include <sstream>
 #include <deque>
 #include <ctime>
 #include <time.h>
 #include <sys/time.h>
 #include <exception>
#include <iomanip>


class PmergeMe
{
    private:
        std::deque<int> _deque;
        std::vector<int> _vector;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &Stk);
        //std::stack<int> getStack() const;
        int parser_arguments(char **s);
        
        std::vector<int>& getVector(); 
        std::deque<int>& getDeque();
        template<typename T>
        void printContainer(T& container) 
        {
            for(typename T::iterator it = container.begin() ; it != container.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
        
        template<typename T>
        void push_back_checked(T& container, const std::string s)
        {
            std::stringstream ss(s);
            int n;
            if (!(ss >> n) || !ss.eof() || n < 0 || n == 0) {
                throw std::invalid_argument("Invalid input: " + s);
            }
            container.push_back(n);
        }
        template<typename T>
        void insert(T& container)
        {
            typename T::value_type key;
            
            int j = 0;
           for (typename T::size_type i = 1; i < container.size(); i++)
            {
                key = container[i];
                j = i - 1;
                while (j >= 0 && container[j] > key)
                {
                    container[j + 1] = container[j];
                    j--;
                }
            container[j + 1] = key;
            }
        }
        template<class Container, class Iter>
        int mergeInsert(Container &merge, Iter begin, Iter end)
        {
            if ((end - begin) <= 1)
                std::iter_swap(begin, end);
            else if ((end - begin) <= 10) 
                insert(merge);
            else
            {
                Iter middle = begin + (std::distance(begin, end) / 2);
                mergeInsert(merge, begin, middle);
                mergeInsert(merge, middle, end);
                std::inplace_merge(begin, middle, end + 1);
            }
            
        
        return (0);
        }
};

#endif // !PmergeMe_HPP
