/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:25:35 by cbustama          #+#    #+#             */
/*   Updated: 2023/01/12 16:35:24 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <cstdarg>
# include <exception>
# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
using std::string;
using std::cout;
using std::cerr;
using std::endl;

class Bureaucrat
{
    private:
        int _grade;
        const std::string _name;
    public:
        Bureaucrat();
        Bureaucrat(int grade, const std::string &name);
        std::ostream& print(std::ostream& os) const;
        
        Bureaucrat(const Bureaucrat  &copy_obj);
        Bureaucrat const &operator=(Bureaucrat const &n_obj);        
        ~Bureaucrat();
        void setGrade(int grade);
        int getGrade()const;
        std::string getName()const;
        Bureaucrat *address_obj(void);
        std::string *address_str(void);
        void increment(void);
        void decrement(void);
        
    class GradeTooHighException: public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade Too High Exception");
            }
    } High;

    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade Too Low Exception");
            }
    } Low;  
        
};
 std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);  
//std::ostream& operator<<(std::ostream& call_obj, Bureaucrat& obj);
#endif
