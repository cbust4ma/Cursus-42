/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:27:49 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/16 00:19:24 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

struct Data{
	int myNum;        
	std::string myString;  

	Data()
	{
		myNum = 10;
		myString = "paco";
	} 
};

uintptr_t   serialize(Data *ptr)
{
	uintptr_t  tmp;
	
	tmp = reinterpret_cast<uintptr_t>(ptr);
	std::cout << "serialising..." << std::endl;
	return (tmp);
}

Data *deserialize(uintptr_t raw)
{
	Data	*tmp;
	tmp = reinterpret_cast<Data *>(raw);
	std::cout << "deserialising..." << std::endl;
	return tmp;
}

int main ()
{
	Data data;
	Data *Data_Deserialize;
	uintptr_t  tmp;

	data.myString = "andy";
	std::cout << "Print data\n" << std::endl;
	std::cout << "Data integer = " << data.myNum << "\nMy string = " << data.myString << std::endl;
	std::cout << "\n" << std::endl;

	tmp = serialize(&data);

	std::cout << "\n↓↓↓↓↓↓↓\n" << std::endl;
	std::cout << "Data integer = " << tmp << "\n\n" << std::endl;

	Data_Deserialize = deserialize(tmp);

	std::cout << "\n↓↓↓↓↓↓↓\n" << std::endl;
	std::cout << "Data integer = " << Data_Deserialize->myNum << "\nMy string = " << Data_Deserialize->myString << std::endl;

	std::cout << "\nmaking changes to check that it is a valid data structure.\n" << std::endl;

	Data_Deserialize->myNum = 2;

	std::cout << "Data integer = " << Data_Deserialize->myNum << "\nMy string = " << Data_Deserialize->myString << std::endl;

}
