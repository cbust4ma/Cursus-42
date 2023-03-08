/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:56:36 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/06 20:02:31 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.cpp"

int main()
{
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
		
	++it;
	--it;
	std::cout << "mstack size (" << mstack.size() << " elements)\n\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	
	std::cout << "s ize (" << s.size() << " elements)\n\n";
	
	for (std::stack<int> tmp = s; !tmp.empty(); tmp.pop())
        std::cout <<"stack print with for " << tmp.top() << '\n';
	std::cout << "s ize (" << s.size() << " elements)\n\n";
	
	std::cout << "Copy constrctor\n";
	MutantStack<int> newMan(mstack);

	std::cout << "newMan (" << newMan.size() << " elements)\n\n";
	std::cout << "other while of copy MutantStack<int> newMan(mstack)" << std::endl;
	
	MutantStack<int>::iterator begin = newMan.begin();
	MutantStack<int>::iterator end = newMan.end();
	std::cout << std::endl;
	
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
	return (0);
}
