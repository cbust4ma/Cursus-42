/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:36:19 by cbustama          #+#    #+#             */
/*   Updated: 2023/01/13 17:27:53 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

        a.setGrade(130);
        c.setGrade(8);
        a.increment();
        c.decrement();
        cout << a;
        cout << c;

        Form prueba("Form1", 2, 3);
        
        prueba.beSigned(a);
        a.signForm(prueba);
   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
  

    return (0);
        
}
