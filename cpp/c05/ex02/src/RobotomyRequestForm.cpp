/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:56:08 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/15 20:07:46 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm():_target(""){}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm(target, 72, 45), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
{
    if (this != &obj)
    {
       if (this->_target!= obj._target)
            this->_target = obj._target; 
    }
}
RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
    
    if (this == &obj)
        return (*this);
    if (this != &obj)
    {
        if (this->_target != obj._target)
             this->_target = obj._target; 
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    //#Required grades: sign 72, exec 45
    
    if (this->getSigned() >= executor.getGrade() && this->getSignedBool())
    {
         	srand((unsigned) time(NULL));
	        int n_random = rand() % 2;

            if (n_random % 2 == 0) 
                std::cout << this->_target << "\a \a \ahas been robotomized successfully \a \a \a" << std::endl;
            else
            {
                std::cout << " Otherwise, informs that the robotomy failed" << std::endl;
            }
    }
    else
    {   
        std::cout << "No grade For Signed You need : " << this->getSigned()  << "For create tree"  << std::endl;
        throw LowForm;
    }
   
    //std::cout << "<" << executor.getName() << ">" <<  "executed" << "<" << AForm::_target << ">" << std::end;
}
