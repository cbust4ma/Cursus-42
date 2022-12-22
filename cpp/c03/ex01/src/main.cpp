/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:23:51 by cbustama          #+#    #+#             */
/*   Updated: 2022/11/29 12:22:43 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
/*
void attack(std::string const & target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
*/

int main()
{
   ScavTrap player_two("Andy");
   
    player_two.takeDamage(20);
    player_two.attack("Any");
    player_two.beRepaired(20);
    player_two.guardGate();
    /*ClapTrap player("Andy");
    player.takeDamage(15);
    player.attack("Any");
    player.beRepaired(15);*/

}

/*std::string _errors(std::string tmp, std::string name)
{
	int	j;
	j = -1;
	while (!std::isalpha(tmp[++j]))
	{
		if (std::cin.eof())
			break;
		std::cin.clear();
		std::cout << "Name fail\nIntroduce " << name << std::endl;
		std::cout << name << " :";
		getline(std::cin, tmp);
		j--;
	}
	return (tmp);
}

int _errors_int(std::string n)
{
    int j = -1;
    int copy;
    
    while (!atoi(n.c_str()) || atoi(n.c_str()) > 100)
	{
		if (std::cin.eof())
			break;
		std::cout << "Number fail\n Introduce Number" << std::endl;
		std::cout << "Number : ";
        //std::cout << n << std::endl;
        //std::cin.clear();
        
		getline(std::cin, n, '\n');
      
        
        
		j--;

	}
    //std::cout << n << std::endl;
    copy =  rand() % 20 + atoi(n.c_str());
    //std::cout << copy << std::endl;
    return (copy);
}

int main()
{
    std::string name;
    std::string name_two;
    std::string attack;
    std::string attack_two;
    int randlife = rand() % 400 + 200;

    std::cout << BOLDGREEN << "Name Player 1" << RESET << std::endl;
    std::cout << ">"; 
    getline(std::cin, name);
    name = _errors(name, "Name Player 1");
    std::cout << BOLDGREEN << "Name Player 2" << RESET << std::endl;
    std::cout << ">";
    
    getline(std::cin, name_two);
    name_two = _errors(name_two, "Name player 2");
    ClapTrap fati(name);
    ClapTrap Soli(name_two);

    Soli.setenergy(randlife);
    fati.setenergy(randlife);
    std::cout << BOLDGREEN << "attack only 0 - 200" << RESET <<  std::endl;
    std::cout << BOLDGREEN << "Damage "<< name << RESET << std:: endl;
    std::cout << "> ";
    getline(std::cin, attack, '\n');
    _errors_int(attack);
    std::cout << BOLDGREEN << "Damage " << name_two << RESET << std:: endl;
    std::cout << "> ";
    getline(std::cin, attack_two, '\n');
    _errors_int(attack_two);
    while(1)
    {
        if (std::cin.eof())
			break;
         std::cout << std::endl;
        std::cout << BOLDWHITE <<   "<-----------------------------" << RESET << BOLDBLUE << "it is the turn of" + name   << RESET << BOLDWHITE  <<  " -------------------------------------------->\n\n" << std::endl;
        
        Soli.sethitpoints(0);
        fati.sethitpoints(0);


        fati.takeDamage(_errors_int(attack));

        fati.attack(name_two);
        Soli.setenergy(Soli.getenergy() - _errors_int(attack));
        if (Soli.getenergy() <= 0 && fati.getenergy() > 0)
        {
            std::cout << BOLDGREEN << "You win " << name_two << RESET << std::endl;
            return (0);
        }
        fati.beRepaired(15);
        std::cout << std::endl;
        std::cout << BOLDWHITE << "<-----------------------------" << RESET  << BOLDBLUE << "it is the turn of" + name_two  << RESET  << BOLDWHITE  <<  " -------------------------------------------->\n\n" << std::endl;
        
        Soli.takeDamage(_errors_int(attack_two));
        Soli.attack(name);
        fati.setenergy(fati.getenergy() - _errors_int(attack_two));
        if (fati.getenergy() <= 0 && Soli.getenergy() > 0)
        {
            std::cout << BOLDGREEN << "You  " << name << RESET << std::endl;
            return (0);
        }
        Soli.beRepaired(15);
    }
    return (0);
}*/
