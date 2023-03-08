/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:14:13 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/24 19:19:17 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>

int main ()
{
    std::vector<int>::iterator it;
    std::vector<int> myvector;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; ++i)
        myvector.push_back(rand()%10 + 1);
    for (it = myvector.begin(); it != myvector.end(); it++)
        std::cout << *it << std::endl;
    try
    {
        //easyfind(myvector, -1);
        //easyfind(myvector, 0);
        //easyfind(myvector, -10315210);
        //easyfind(myvector, 564224652);
        easyfind(myvector, 4);
        easyfind(myvector, 3);
        easyfind(myvector, 8);
        easyfind(myvector, 2);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error Not found item" << e.what() << std::endl;
    }
    return (0);
}
