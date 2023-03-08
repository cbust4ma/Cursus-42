/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:40 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/15 20:25:27 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void    AForm::beSigned(Bureaucrat tosign)
{
    if (tosign.getGrade() <= this->_GradeSigned)
        this->_SignedBool = true;
    //else
      //  throw LowForm;
}

AForm::AForm():_FormName("No_Name"),_GradeSigned(0), _GradeExec(0)
{
    if (_GradeSigned <= 0 || _GradeExec <= 0)
        throw HighForm;
    if (_GradeSigned > 150 || _GradeExec > 150)
        throw LowForm;
      
}

AForm::AForm(const std::string name, const int GradeSigned, const int GradeExec)
:_FormName(name),_GradeSigned(GradeSigned), _GradeExec(GradeExec)
{
    if (_GradeSigned <= 0 || _GradeExec <= 0)
        throw HighForm;
    if (_GradeSigned > 150 || _GradeExec > 150)
        throw LowForm;
    this->_SignedBool = false;
    
}

AForm::~AForm()
{
   
}

AForm::AForm(const AForm &copy_obj):_FormName(copy_obj._FormName),
 _GradeSigned(copy_obj._GradeSigned), _GradeExec(copy_obj._GradeExec)
{
    
    if (this != &copy_obj)
    {
       if (this->_SignedBool != copy_obj._SignedBool)
            this->_SignedBool = copy_obj._SignedBool; 
    }
}
AForm const &AForm::operator=(AForm const &obj)
{
    
    if (this == &obj)
        return (*this);
    if (this != &obj)
    {
        if (this->_SignedBool != obj._SignedBool)
             this->_SignedBool = obj._SignedBool; 
    }
    return (*this);
}
std::ostream& AForm::PrintForm(std::ostream& os, std::string name) const
{
    cout << name << endl;
    if (this->getSignedBool() == true)
        return os << BOLDGREEN "<Bureaucrat " << name << ">" RESET << BOLDBLUE " Signed " RESET << BOLDGREEN "<" << this->_FormName << ">" RESET << endl;
    else
    {
        return os << BOLDGREEN "< Bureaucrat " << name << ">" RESET << BOLDBLUE "couldn’t sign" RESET << BOLDGREEN "<" << 
        this->_FormName << ">" RESET << BOLDGREEN "because Grade_signed Conflict " << this->_GradeSigned << ">" RESET << "and Grade Exec "<<
         this->_GradeExec  << "and bool " << this->_SignedBool <<endl; 
    }
}

bool AForm::getSignedBool(void)const
{
    return (this->_SignedBool);
}

std::ostream& operator<<(std::ostream& os, AForm& obj) 
{
    return obj.PrintForm(os, obj.name_bure);
}

int AForm::getSigned() const
{
    return (this->_GradeSigned);
}

int AForm::getExec() const
{
    return (this->_GradeExec);
}

std::string AForm::getName() const
{
    return (this->_FormName);
}
