/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:31:18 by cbustama          #+#    #+#             */
/*   Updated: 2022/09/28 18:32:17 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
//#include <time.h>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

//_accountIndex = 0;
//index_ = 0;

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	//index_ = (this->_accountIndex + index_); 
	std::cout << " accounts:"  << getNbAccounts() << ";total:" << getTotalAmount() <<  ";deposits:" << getNbDeposits() \
		<< ";withdrawals:"<< getNbWithdrawals() << std::endl;
	return ;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	//index_ = (this->_accountIndex + index_); 
	std::cout << " index:"  << getNbAccounts() << ";amount:" << initial_deposit <<  ";created" << std::endl;
	//std::cout << "a" << initial_deposit << std::endl ;
	_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	return ;
}


Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:"  << this->_accountIndex << ";amount:" << this->_amount <<  ";closed" << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	int tmp;
//	std::cout << " Index:"  << getNbAccounts() << ";amount:" << initial_deposit <<  ";created" << std::endl;

	_totalNbDeposits++;//std::cout << deposit << std::endl;
	_totalAmount += deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	tmp = (this->_amount - deposit);

	_displayTimestamp();
	std::cout << " index:"  << this->_accountIndex << ";p_amount:" << tmp \
		<< ";deposit:" << deposit << ";amount:" << this->_amount \
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;



	return ;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	int tmp;
	
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:"  << this->_accountIndex << ";p_amount:" << this->_amount \
			<< ";withdrawal:" << "refused" << std::endl;
		return (false);
	}
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	tmp = (this->_amount + withdrawal);
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:"  << this->_accountIndex << ";p_amount:" << tmp\
	<< ";withdrawal:" << withdrawal << ";amount:" << this->_amount \
	<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
	//std::cout << withdrawal << std::endl;
	//return (0);
}
int		Account::checkAmount() const
{
	return (this->_amount);
}
void	Account::displayStatus() const
{
	//std::cout << this->_amount
	_displayTimestamp();
	std::cout << " index:"  << this->_accountIndex << ";amount:" << this->_amount \
		<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;

	
	return ;

}

void	Account::_displayTimestamp()
{
	time_t	c_t;
	tm		*crt;
	char	t[16];

	time(&c_t);
	crt = localtime(&c_t);
	std::strftime(t, 16, "%Y%m%d_%H%M%S", crt);
	std::cout << '[' << t << ']';
}
