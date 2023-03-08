/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:37:47 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/21 19:37:49 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
#include <stdexcept>


template <typename T>

/**/
class Array
{
	T *_array;
	std::size_t n_elements;
	public:
		Array<T>():n_elements(0)
		{
			this->_array = new T[n_elements];
		};
		Array<T>(unsigned int n):n_elements(n)
		{
			this->_array = new T[n];
		};
		Array<T>(const Array<T> &Arr)
		{
			if (this->n_elements != Arr.n_elements)
				this->n_elements = Arr.n_elements;
			if (this->_array != Arr._array)
			{
				this->_array = new T[n_elements];
				for(std::size_t count = 0; count < n_elements; count++)
					this->_array[count] = Arr._array[count];
			}
		};
		T &operator=(const Array<T> &Arr)
		{
			if (this->n_elements!= Arr.n_elements)
				this->n_elements = Arr.n_elements;
			if (this->_array != Arr._array)
			{
				this->_array = new T[n_elements];
				for(std::size_t count = 0; count < n_elements; count++)
					this->_array[count] = Arr._array[count];
			}

			return (*this);
		};
		T operator[](const std::size_t i) const
		{
			if (i < 0 || i >= n_elements)
				throw std::out_of_range("Element is out of the limits of the Array.");
			return (this->_array[i]);
		};

		T &operator[](std::size_t i)
		{
			if (i < 0 || i >= n_elements)
				throw std::out_of_range("Element is out of the limits of the Array.");
			return (this->_array[i]);
		};
		std::size_t size() const {return (n_elements);};
		~Array(){ delete [] this->_array;};

};

#endif
