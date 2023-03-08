/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:10:50 by cbustama          #+#    #+#             */
/*   Updated: 2023/01/13 19:00:40 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():_grade(0), _name("No_Name_const")
{
    cout << "Constructor default Bureaucrat called" << endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string &name):_name(name)
{
    this->_grade = grade;
    if (this->getGrade() >= 151)
        throw Low;
    else if (this->getGrade() <= 0)
        throw High;
    cout << "Constructor Bureaucrat called" << endl;
}
       
Bureaucrat::Bureaucrat(const Bureaucrat &copy_obj):_name(copy_obj._name)
{  
    cout << "Deep copy Bureaucrat called " << endl;
    if (this != &copy_obj)
    {
        if(this->_grade != copy_obj._grade)
            this->_grade = copy_obj._grade;
    }      
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &n_obj)
{
    cout << "Calls Bureaucrat copy assignment operator" << endl;
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
    cout << "Bureaucrat destructor called" << endl;
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

void    Bureaucrat::signForm(Form &form)
{
    form.name_bure = this->getName();
    cout << form;
}
