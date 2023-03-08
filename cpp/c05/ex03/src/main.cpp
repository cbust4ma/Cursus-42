/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:36:19 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/15 21:29:18 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main ()
{
    try
    {
     
       /* Bureaucrat d(130, "Ma");
       
        
        ShrubberyCreationForm prueba("hola");
        prueba.beSigned(d);
        d.signForm(prueba);
        prueba.execute(d);*/

        Bureaucrat Manu(5, "Cabeza");

        RobotomyRequestForm Home("ADB");
        ShrubberyCreationForm  uno("Shruberry");
        PresidentialPardonForm dos("President");
  
       
        Home.beSigned(Manu);
        uno.beSigned(Manu);
        dos.beSigned(Manu);
     
        Manu.signForm(Home);
        Manu.signForm(uno);
        Manu.signForm(dos);
        //Home.execute(Manu);
        Manu.executeForm(Home);
        std::cout<< "\n\n";
        Manu.executeForm(dos);
        Manu.executeForm(uno);
        
        {
    
            Intern someRandomIntern;
            AForm *rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            //rrf->beSigned(Manu);
            //rrf->execute(Manu);
            delete rrf;
        }
   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
  

    return (0);
        
}
