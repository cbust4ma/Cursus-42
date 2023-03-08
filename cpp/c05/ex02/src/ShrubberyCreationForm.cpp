/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:56:08 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/15 19:37:26 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():_target(""){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm(target, 145, 137), _target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
    {
       if (this->_target!= obj._target)
            this->_target = obj._target; 
    }
}
ShrubberyCreationForm const &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    //#Required grades: sign 145, exec 137
    
    if (this->getSigned() >= executor.getGrade() && this->getSignedBool())
    {
        std::ofstream MyFile(_target+"_shrubbery");
        MyFile <<"        _-_\n";
        MyFile <<"     /~~   ~~\\ \n";
        MyFile <<"  /~~         ~~\\ \n";
        MyFile <<" {               }\n";
        MyFile <<"  \\  _-     -_  /\n";
        MyFile <<"    ~  \\\\ //  ~\n";
        MyFile <<" _- -   | | _- _\n";
        MyFile <<"   _ -  | |   -_\n";
        MyFile <<"       // \\\\ \n";

         MyFile.close();
    }
    else if (this->getSignedBool() == false)
        std::cout << "No signed" << std::endl;
    else
    {   
        std::cout << "No grade For Signed You need : " << this->getSigned()  << "For create tree"  << std::endl;
        throw LowForm;
    }
   if (this->getExec() >= executor.getGrade() && this->getSignedBool())
    {
        std::ifstream MyFile;
        std::string myText;
        MyFile.open("./"+_target+"_shrubbery");
        while (getline (MyFile, myText))
        {
            cout << myText;
            std::cout << std::endl;
        }
        MyFile.close();
    }
    else if (this->getSignedBool() == false)
        std::cout << "No signed" << std::endl;
    else
    {
        std::cout << "No grade execution You need: " << this->getExec() << " for execute you grade is " << executor.getGrade() << std::endl;
        throw LowForm;
    }
    //std::cout << "<" << executor.getName() << ">" <<  "executed" << "<" << AForm::_target << ">" << std::end;
}
