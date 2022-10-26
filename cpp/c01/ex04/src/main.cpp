

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:32:47 by cbustama          #+#    #+#             */
/*   Updated: 2022/10/06 20:38:53 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using std::cout;
using std::string;
using std::endl;

void	_errors_empty(int n)
{
	cout.flush();
	cout << "\x1B[2J\x1B[H";
	if (n == 0)
		std::cerr << "s1 or s2 no exist\n" << endl;
	else if (n == 1)
		std::cerr << "File  empty/ or no exist\n" << endl;
	else if (n == 2)
		std::cerr << "No exist s1 in file\n" << endl;
	else if (n == 3)
		std::cerr << "Error <bad> arguments only [3]" << std::endl;
	cout << "The arguments for this program are:" << endl << "1. [ FILE ]    The file from wich the program will read" 
	<< endl << "2. [ SEARCH ]  The string the program will try to find for later substitution" 
	<< endl << "3. [ NEW STR ] The string that will substitute all the coincidences of [ SEARCH ] inside [ FILE ]" << endl;
	return ;
}

void	_replace(string file, string  s1, string s2)
{

	std::ifstream	file_r(file);
	string 			line;
	string 			tp;
	int				tmp;


	if(!file_r || file_r.peek() == EOF)
		_errors_empty(1);
	else if (s1.empty() || s2.empty())
		_errors_empty(0);
	else
	{
		std::ofstream otherfile(file.append(".replace"));
		while (getline(file_r, tp))
			line.append(tp + '\n');
		if (line.find(s1) == string::npos)
			_errors_empty(2);
		line.erase(line.length() -1, '\n');
		while(line.find(s1) != string::npos)
		{
			tmp = line.find(s1);
			cout << "pos : " << tmp << endl;
			line.erase(tmp, s1.length());
			line.insert(tmp, s2);
		}
		otherfile << line ;
	}
}

int main (int argc, char *argv[])
{
	string line;
	if(argc != 4)
		_errors_empty(3);
	else
		_replace(argv[1], argv[2], argv[3]);
	
	return (0);
}
