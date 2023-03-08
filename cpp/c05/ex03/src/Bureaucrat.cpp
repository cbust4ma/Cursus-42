/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:10:50 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/15 20:25:11 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>

Bureaucrat::Bureaucrat():_grade(0), _name("No_Name_const")
{
    
}

Bureaucrat::Bureaucrat(int grade, const std::string &name):_name(name)
{
    this->_grade = grade;
   
    if (this->getGrade() >= 151)
        throw Low;
    else if (this->getGrade() <= 0)
        throw High;
    
}
       
Bureaucrat::Bureaucrat(const Bureaucrat &copy_obj):_name(copy_obj._name)
{  
    if (this != &copy_obj)
    {
        if(this->_grade != copy_obj._grade)
            this->_grade = copy_obj._grade;
    }      
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &n_obj)
{
    // Guard self assignment
    if (this == & n_obj)
        return (*this);
    if (this != & n_obj)
    {
        if(this->_grade != n_obj._grade)
            this->_grade = n_obj._grade;
    }
    return (*this);
}     

Bureaucrat::~Bureaucrat()
{
   
}

void Bureaucrat::setGrade(int grade)
{
    this->_grade = grade;
}

int Bureaucrat::getGrade()const
{
    return (this->_grade);
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

/*std::ostream& operator<<(std::ostream& call_obj, Bureaucrat &obj)
{
    int n;
 
    n = obj.getGrade();
    //n = obj.getRawBits();
    call_obj << n;
    
    return call_obj;
}
*/
std::ostream& Bureaucrat::print(std::ostream& os) const 
{
    //<name>, bureaucrat grade <grade>.
    return os << BOLDGREEN "<"+_name+">" RESET << BOLDBLUE " bureaucrat grade " RESET << BOLDGREEN "<" << _grade << ">" RESET << endl;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj) {
    return obj.print(os);
}

std::string *Bureaucrat::address_str()
{
    return ((std::string *)&_name);
}

Bureaucrat *Bureaucrat::address_obj()
{
    return (this);
}

void Bureaucrat::increment()
{
    if (this->getGrade() <= 1)
        throw High;
    else
    {
        this->_grade--;
        cout << GREEN "Bureaucrat Increment" RESET << endl;
    }
}

void Bureaucrat::decrement()
{
    if (this->getGrade() >= 150)
        throw Low;
    else
    {
        this->_grade++;
        cout << RED "Bureaucrat Decrement" RESET << endl;
    }      
}

void    Bureaucrat::signForm(AForm &form)
{
    form.name_bure = this->getName();
    cout << form;
}

void Bureaucrat::executeForm(AForm const & form)
{
    if (form.getSigned() && form.getExec() >= this->getGrade())
    {
        form.execute(*this);
    }
    else
    {
        std::cout << "NO grade execute in bureaucrat form" << std::endl;
    }
}
