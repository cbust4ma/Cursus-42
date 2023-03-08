/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:36:19 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/13 19:02:46 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    try
    {
        Bureaucrat a(150, "Juan");

        cout << a.getName() << endl;
        Bureaucrat c(a);
        
        cout << a.address_obj() << endl;
        cout << c.address_obj() << endl;
        cout << a.address_obj() << endl;

        a.setGrade(2);
        c.setGrade(8);
        a.increment();
        c.decrement();
        cout << a;
        cout << c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return (0);
        
}
