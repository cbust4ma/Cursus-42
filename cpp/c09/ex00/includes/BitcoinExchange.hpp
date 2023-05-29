/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:57:07 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/27 21:08:16 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP
    #include <cstddef>
    #include <ios>
    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <map>
    #include <sstream>
    #include <string> 
    #include <cstdlib>
    #include <ctime>
    #include <algorithm>

class BitcoinExchange
{
    private:
        std::stack<int> _data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &Stk);
        std::string other_date(std::map<std::string, std::string> data,  std::string date);
        int isInt(std::string s, int &n);
        float isFloat(std::string s, float &f);
        int	check_date(std::string str);
        void	printBBDD(std::map<std::string, std::string> data);
        std::map<std::string, std::string> fillData(std::map<std::string, std::string> map, std::string delimiter, std::string str);
        std::map<std::string, std::string> BBDD();
        void readFile(std::string file);

};
 #endif
