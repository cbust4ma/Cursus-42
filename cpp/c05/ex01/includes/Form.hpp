/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:19:50 by cbustama          #+#    #+#             */
/*   Updated: 2023/01/13 19:01:37 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# define RESET   "\033[0m"
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
using std::string;
using std::cout;
using std::cerr;
using std::endl;

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string _FormName;
        bool             _SignedBool;
        const int       _GradeSigned;
        const int       _GradeExec;
    public:
        void    beSigned(Bureaucrat tosigned);
        
        Form();
        Form(const std::string name, const int GradeSigned, const int GradeExec);
        ~Form();
        Form(const Form &copy_obj);
        Form const &operator=(Form const &obj);
        std::ostream& PrintForm(std::ostream& os, std::string name) const;
        bool getSignedBool(void)const;
        std::string name_bure;
        
    class GradeTooHighException: public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return (BOLDRED "Grade Too High Exception To Sign" RESET);
            }
    } HighForm;

    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return (BOLDRED "Grade Too Low Exception To Sign" RESET);
            }
    } LowForm; 
};
std::ostream& operator<<(std::ostream& os, Form& obj); 
#endif
