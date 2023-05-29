/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:01:01 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/27 21:11:36 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange():_data()
{
    
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    this->_data = copy._data;

}

BitcoinExchange::~BitcoinExchange()
{
    
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &Stk)
{
    this->_data  = Stk._data;
    return (*this);
}

std::string BitcoinExchange::other_date(std::map<std::string, std::string> _data,  std::string date)
{
	std::map<std::string, std::string>::iterator it;
	std::map<std::string, std::string>::iterator it2 = _data.find(date);
	std::string prev_date;

	if (it2 != _data.end())
	{
		return (date);
	}
		
	for(it = _data.begin(); it != _data.end(); it++)
	{
		if (it->first >= date)
			break;
		prev_date = it->first;
	}
	if (prev_date.empty())
		 std::cout << "No hay fechas anteriores." << std::endl;
	return(prev_date);
}

int BitcoinExchange::isInt(std::string s, int &n)
{
	std::stringstream ss(s);
	//ss >> n && ss.eof();
	return (ss >> n && ss.eof());
}

float BitcoinExchange::isFloat(std::string s, float &f)
{
	std::stringstream ss(s);
	char string;
	if (ss >> f && !(ss >> string))
		return (f);
	else
	{
		return (-1);
	}
}

int	BitcoinExchange::check_date(std::string str)
{
	struct tm time = {};
	return (strptime(str.c_str(), "%Y-%m-%d", &time) == NULL);
}

void	BitcoinExchange::printBBDD(std::map<std::string, std::string> _data)
{
	for (std::map<std::string, std::string>::iterator it = _data.begin(); it != _data.end(); ++it) {
        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
    }
}

std::map<std::string, std::string> BitcoinExchange::fillData(std::map<std::string, std::string> map, std::string delimiter, std::string str)
{
	std::ifstream end(str.c_str());
	size_t pos = 0;
	std::string date;
	std::string aLine;

	std::getline(end, aLine);
	while (std::getline(end, aLine))
	{
		pos = aLine.find(delimiter);
		//if (pos  != 10)
		//		map.insert(std::make_pair(aLine, ""));
		if (pos != std::string::npos)
		{
			date = aLine.substr(0, pos);
			aLine.erase(0, pos + delimiter.length());
			map.insert(std::make_pair(date, aLine));
		}
	}
	end.close();
	return (map);
}

std::map<std::string, std::string> BitcoinExchange::BBDD()
{
	//std::ifstream end(static_cast<std::string>("_data.csv").c_str());
	std::string delimiter = ",";
	std::map<std::string, std::string> _data;

	_data = fillData(_data, delimiter, "data.csv");
	//printBBDD(_data);
	//std::cout << _data.size() << " <<< ==== tamaño BBDd" << std::endl;
	return (_data);
}

void BitcoinExchange::readFile(std::string file)
{
	std::ifstream end(file.c_str());
	std::string delimiter = " | ";
	std::string aLine;
	std::string date;
	size_t pos = 0;
	float 	f;
	int		n;
	std::map<std::string, std::string> BBD;

	if (end.fail())
	{
		std::cerr << file << " Error. could not open file." << std::endl;
		return ;
	}
	std::getline(end, aLine);
	if (aLine != "date | value")
	{
		std::cerr << file << " Error. could not open file." << std::endl;
		return ;
	}

	BBD = BBDD();
	while (std::getline(end, aLine))
	{
		pos = aLine.find(delimiter);
		if (pos  != 10)
		{
			if (check_date(aLine))
				std::cout << "Error: bad input => " << aLine << std::endl;
		}
				//map.insert(std::make_pair(aLine, ""));
		else if (pos != std::string::npos)
		{
			date = aLine.substr(0, pos);
			if (check_date(date))
				std::cout << "Error: bad input => " << date << std::endl;
			

			aLine.erase(0, pos + delimiter.length());
			std::map<std::string, std::string>::iterator it = BBD.find(other_date(BBD, date));
			
			if ( it != BBD.end())
			{
				if (isInt(aLine, n))
				{
					
					if (n > 1000)
						std::cout << "Error: too large a number." << std::endl;
					else if (n < 0)
						std::cout << "Error: not a positive number." << std::endl;
					else
						std::cout << date << " => " << n << " = "  << atof(it->second.c_str()) * n << std::endl;
				}
				else if (isFloat(aLine, f))
				{
					if (f > 1000.0)
						std::cout << "Error: too large a number." << std::endl;
					else if (f < 0.0 || f == -1)
						std::cout << "Error: not a positive number." << std::endl;
					else
						std::cout << date << " => " << f << " = "  << atof(it->second.c_str()) * f << std::endl;
				}
			}
		}
	}
	end.close();
}
