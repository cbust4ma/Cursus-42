/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:54:06 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/16 01:05:01 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <cstdlib> 
#include <iomanip>

std::string check_value(std::string str)
{
    __unused int count = 0;
    std::size_t repeat = 0;
    for (int i = 0; i < static_cast<int>(str.length()); i++)
    {
        //if (str[i] != '.' && (str[str.length()-1] != 'f' && !isalpha(str[i])))
          //  return ("digit");

        if (std::isalpha((str[i])))
        {
            if(str[repeat] == str[repeat + 1])
                return ("imposible");
            if (std::isdigit(str[i - 1]))
                return ("imposible");
            if (str.length() >= 2)
                return ("ignore");
            return("alpha");
        }
        else if (str[str.length()-1] == 'f' && str[i] == '.')
        {
            if (!std::isdigit(str[str.length() - 2]))
                return ("imposible");
            return ("float");
        }
        else if (str[i] == '.')
        {
            while (str[i++])
                if (std::isalpha(str[i]))
                    return ("imposible");
            return ("double");
        }
    }
    return ("digit");
}

void print_data(int is_int, float is_float, double is_double, char is_char, int check)
{
    if (check == 1)
    {
        std::cout << "char: imposible" << std::endl;
        std::cout << "int: impossible "<< std::endl;
    }
    else if (isprint(is_int))
        std::cout << "char: '" << is_char << "'" << std::endl;
    else if (check == 0)
        std::cout << "char: Non Displayable" << std::endl;
    
    if (check == 0)
        std::cout << "int: "<< is_int << std::endl;
    if (check == 2)
    {
        std::cout << "char: imposible" << std::endl;
        std::cout << "int: impossible "<< std::endl;
        std::cout << "float: impossible"<< std::endl;
        std::cout << "double: impossible"<< std::endl;
    }
    else
    {
        std::cout << "float: "<< is_float << 'f' << std::endl;
        std::cout << "double: "<< is_double << std::endl;
    }
}

void cast_value(std::string type, char *argv)
{
    int     is_int = 0;
    float   is_float = 0.0f;
    double  is_double = 0.0;
    char    is_char = 0;
    int    check = 0;

    std::cout << type << std::endl;
    if (type == "digit")
    {
        is_int = atoi(argv);
        is_float = static_cast <float>(is_int );
        is_double = static_cast<double>(is_int);
    }
    else if(type == "float")
    {
        is_float = atof(argv);
        is_int = static_cast<int>(is_float);
        is_double = static_cast<double>(is_float);
    }

    else if (type == "double")
    {
        is_double = atof(argv);
        is_float = static_cast<float>(is_double);
        is_int = static_cast<int>(is_double);
    }
    else if (isascii(atoi(argv)))
    {
        if (check_value(argv) == "ignore")
        {
            check = 1;
            is_float = static_cast <float>(atof(argv));
            is_double = static_cast<double>(atof(argv));
        }
        else
        {
            is_int = static_cast<int>(*argv);
            is_float = static_cast <float>(is_int);
            is_double = static_cast<double>(is_int);

        }
        if (check_value(argv) == "imposible")
        {
            is_int = 0;
            is_float = 0;
            is_double = 0;
            check = 2;
        }

    }
    is_char = is_int; 
    print_data(is_int, is_float, is_double, is_char, check);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << "Only one parameter is accepted." << std::endl, 1);
    if (strlen(argv[1]) > 5)
    {
        std::cerr << "limit number" << std::endl;
        return (1);
    }
    std::cout << std::setprecision(1) << std::fixed;
    cast_value(check_value(argv[1]), argv[1]);
    return (0);
}
