/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:23:47 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:55 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>
        
RPN::RPN():_stackRpn()
{}

RPN::RPN(const RPN &Stk)
{
    this->_stackRpn = Stk._stackRpn;
}

RPN::~RPN(){}

RPN &RPN::operator=(const RPN &Stk)
{
    this->_stackRpn = Stk._stackRpn;
    return (*this);
}

std::stack<int> RPN::getStack() const
{
    return (this->_stackRpn);
}

bool RPN::isInt(std::string s, int &n)
{
    std::stringstream ss(s);
    return(ss >> n && ss.eof());
}

int    RPN::checkSign(unsigned char sign, int a, int b)
{
    int result;
    
    result = 0;
     
    switch(sign)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    }
    return (result);
}

int    RPN::rpn(std::string str)
{
    int result = 0;
    std::string::const_iterator it;
    int a;
    int b;
    int n;
    
    if (str.empty())
        return 1;
    for (it = str.begin(); it != str.end(); ++it)
    {
        std::string number(1, *it);
        if (isInt(number, n))
            _stackRpn.push(n);
        else if(*it == '+' || *it == '-'  || *it == '*'  || *it == '/')
        {
            
            if (_stackRpn.size() > 1)
            {
                if (_stackRpn.size() < 2)
                {
                    std::cout << "Error: not enough operands" << std::endl;
                    return 1;
                }                
                b = _stackRpn.top();
                _stackRpn.pop();
                a = _stackRpn.top();
                if (*it == '/' && b == 0)
                {
                    std::cout << "Error: division by zero" << std::endl;
                    return 1;
                }
                _stackRpn.pop();
                result = checkSign(*it, a, b);
                _stackRpn.push(result);
            }
            else
            {
                std::cout << _stackRpn.size() << std::endl;
                std::cout << "ERROR" << std::endl;
                return (1);
            } 
        }
        else if (*it != ' ')
            {
                 std::cout << "Error: invalid character" << std::endl;
                return  (1);
            }
    }
    if (_stackRpn.size() != 1)
    {
        std::cout << _stackRpn.size() << "\n";
        std::cout << "Error: too many operands" << std::endl;
        return 1;
    }
    std::cout << _stackRpn.top() << std::endl;
    return (0);
}
