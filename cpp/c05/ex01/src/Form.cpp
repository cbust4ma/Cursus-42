/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:40 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/14 22:06:55 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void    Form::beSigned(Bureaucrat tosign)
{
    if (tosign.getGrade() <= this->_GradeSigned)
        this->_SignedBool = true;
    //else
      //  throw LowForm;
}



Form::Form():_FormName("No_Name"),_GradeSigned(0), _GradeExec(0)
{
    if (_GradeSigned <= 0 || _GradeExec <= 0)
        throw HighForm;
    if (_GradeSigned > 150 || _GradeExec > 150)
        throw LowForm;
    cout << "Constructor Default Form Called" << endl;    
}

Form::Form(const std::string name, const int GradeSigned, const int GradeExec)
:_FormName(name),_GradeSigned(GradeSigned), _GradeExec(GradeExec)
{
    if (_GradeSigned <= 0 || _GradeExec <= 0)
        throw HighForm;
    if (_GradeSigned > 150 || _GradeExec > 150)
        throw LowForm;
    this->_SignedBool = false;
    cout << "Constructor Form Called" << endl; 
}

Form::~Form()
{
    cout << "Destructor Form Called" << endl;
}

Form::Form(const Form &copy_obj):_FormName(copy_obj._FormName),
 _GradeSigned(copy_obj._GradeSigned), _GradeExec(copy_obj._GradeExec)
{
    cout << "Deep Copy Form called" << endl;
    if (this != &copy_obj)
    {
       if (this->_SignedBool != copy_obj._SignedBool)
            this->_SignedBool = copy_obj._SignedBool; 
    }
}
Form const &Form::operator=(Form const &obj)
{
    cout << "Call Form Copy Assignament operator" << endl;
    if (this == &obj)
        return (*this);
    if (this != &obj)
    {
        if (this->_SignedBool != obj._SignedBool)
             this->_SignedBool = obj._SignedBool; 
    }
    return (*this);
}
std::ostream& Form::PrintForm(std::ostream& os, std::string name) const
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

bool Form::getSignedBool(void)const
{
    return (this->_SignedBool);
}

std::ostream& operator<<(std::ostream& os, Form& obj) 
{
    return obj.PrintForm(os, obj.name_bure);
}
