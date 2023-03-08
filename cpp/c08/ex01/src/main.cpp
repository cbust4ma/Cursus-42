/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:42:10 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/24 21:41:27 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <span.hpp>

int main()
{
    span sp = span(5);
    try
    {
        sp.addNumber(5);
        sp.addNumber(11);
        sp.addNumber(9);
        sp.addNumber(17);
        sp.addNumber(3);
        std::cout << "size sp = " << sp.get().size() << std::endl;
        std::vector<int>::iterator it;
        for (it = sp.get().begin(); it != sp.get().end(); it++)
            std::cout << *it << std::endl;
        
        std::cout << "\nShortespan()\n" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << "\nLongespan()\n" << std::endl;
        std::cout << sp.longestSpan() << std::endl;
            
    }
    catch (const std::exception &e)
    {
        std::cout << "Error Number repeat" << e.what() << std::endl;
    }

    return (0);
}
