/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:37:24 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/15 21:21:00 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &obj){(void)obj;}

Intern const &Intern::operator=(Intern const &obj){(void)obj; return (*this);}

AForm *Intern::makeForm(std::string typeForm, std::string  target)
{
    int i = 3;
    std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    for (int parameters = 0; parameters < 3; parameters++)
    {
        if (typeForm == arr[parameters])
        {
            i = parameters;
            break;
        }        
    }
    switch (i)
    {
        case 0:
            return (new ShrubberyCreationForm(target));
            break;
        case 1:
            std::cout<< "hola" << std::endl;
            return (new RobotomyRequestForm(target));
            break;
        case 2:
            return (new PresidentialPardonForm(target));
            break;
        default:
            std::cerr << "If the form name passed as parameter doesn’t exist, print an explicit error message\n";
            throw InternEx;
            break;
    }
}

