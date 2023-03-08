/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:43:45 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/06 20:07:19 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>

template <typename T>

void easyfind(T &myvector, int n)
{
    std::cout << "search.... " << n << std::endl;
    std::vector<int>::iterator it;
    it = find(myvector.begin(), myvector.end(), n);
    if (it != myvector.end())
        std::cout << "found " <<  *it << " and index is == " << it - myvector.begin() << std::endl;
    else
        throw std::out_of_range("");       
}
#endif
