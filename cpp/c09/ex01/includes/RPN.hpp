/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:14:13 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/27 20:48:58 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
 #define RPN_HPP
 #include <iostream>
    #include <stack>
    #include <string>
    #include <stack>
    #include <cstdlib>
    #include <sstream>
    #include <cctype>

class RPN
{
    private:
        std::stack<int> _stackRpn;
    public:
        RPN();
        RPN(const RPN &copy);
        ~RPN();
        RPN &operator=(const RPN &Stk);
        std::stack<int> getStack() const;
        bool isInt(std::string s, int &n);
        int    checkSign(unsigned char sign, int a, int b);
        int    rpn(std::string str);
};

#endif // !RPN_HPP
