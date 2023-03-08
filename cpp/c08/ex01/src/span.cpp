/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:24:21 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/24 21:42:20 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <span.hpp>

span::span(){}

span::span(int n):_n(n)
{
    //this->myvector = std::vector<int> prueba(n);
    //this->myvector.resize(n);
}

span::~span(){}

span::span(const span  &copy_obj)
{
    if (this !=  &copy_obj)
    {
        if (this->_n != copy_obj._n)
            this->_n = copy_obj._n;
        if (this->myvector != copy_obj.myvector)
            this->myvector = copy_obj.myvector;
    }
}

span const &span::operator=(span const &copy_obj)
{
    if (this == &copy_obj)
        return (*this);
    if (this !=  &copy_obj)
    {
        if (this->_n != copy_obj._n)
            this->_n = copy_obj._n;
        if (this->myvector != copy_obj.myvector)
            this->myvector = copy_obj.myvector;
    }          
    return (*this);
}

std::vector<int> &span::get()
{
    return (this->myvector);    
}

void span::addNumber(int n)
{
    std::vector<int>::iterator it;
    it = find(this->myvector.begin(), this->myvector.end(), n);
    if (it != this->myvector.end())
        throw std::exception();
    else
    {
        if (myvector.size() < static_cast<unsigned long>(this->_n))
            this->myvector.push_back(n);
        else
        {
            std::cout << "Te has excedido" << std::endl;
            throw std::out_of_range(" or exceed ");
            return ;
        }
    }
}

int span::shortestSpan()
{
    int distance;
    std::vector<int>::iterator it;
     
     sort(myvector.begin(), myvector.end());
     it = myvector.begin();
     distance = *it;
     it++;
     distance = abs(distance - *it);
     for (it = myvector.begin(); it != myvector.end(); it++)
     {
        int newDist = *it;
        it++;
        if (it == myvector.end())
            return (distance);
        newDist = abs(newDist - *it);
        it--;
        if (distance > newDist)
            distance = newDist;
     }
    return (distance);
}

int span::longestSpan()
{
    int distance;

    sort(myvector.begin(), myvector.end());
    distance = *(--myvector.end()) - *myvector.begin();
    return (distance);
}
