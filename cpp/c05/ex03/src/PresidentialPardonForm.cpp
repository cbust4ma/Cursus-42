/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:56:08 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/15 20:19:25 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm():_target(""){}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm(target, 25, 5), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
{
    if (this != &obj)
    {
       if (this->_target!= obj._target)
            this->_target = obj._target; 
    }
}
PresidentialPardonForm const &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
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

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    //#Required grades: sign 25, exec 5
    
    if (this->getSigned() >= executor.getGrade() && this->getSignedBool())
        std::cout << this->_target << "has been pardoned by Zaphod Beeblebrox" << std::endl;

    else
    {   
        std::cout << "No grade For Signed You need : " << this->getSigned()  << "For create tree"  << std::endl;
        throw LowForm;
    }
   
    //std::cout << "<" << executor.getName() << ">" <<  "executed" << "<" << AForm::_target << ">" << std::end;
}
