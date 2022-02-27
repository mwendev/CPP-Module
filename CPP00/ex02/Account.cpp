/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:42:14 by mwen              #+#    #+#             */
/*   Updated: 2022/02/08 20:56:46 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();

	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created" << std::endl;

	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account()
{
	Account::_displayTimestamp();

	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts( void ) {return (Account::_nbAccounts);}
int	Account::getTotalAmount( void ) {return (Account::_totalAmount);}
int	Account::getNbDeposits( void ) {return (Account::_totalNbDeposits);}
int	Account::getNbWithdrawals( void ) {return (Account::_totalNbWithdrawals);}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();

	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t	t		= std::time(0);
	std::tm		*now	= std::localtime(&t);

	std::cout << "[" << (now->tm_year + 1900);
	if ((now->tm_mon + 1) < 9)
		std::cout << 0;
	std::cout << (now->tm_mon + 1);
	if (now->tm_mday < 9)
		std::cout << 0;
	std::cout << (now->tm_mday) << "_";
	if (now->tm_hour < 9)
		std::cout << 0;
	std::cout << now->tm_hour;
	if (now->tm_min < 9)
		std::cout << 0;
	std::cout << now->tm_min;
	if (now->tm_sec < 9)
		std::cout << 0;
	std::cout << now->tm_sec;
	std::cout << "] ";
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();

	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	std::cout << "deposit:";
	if (deposit < 0)
		std::cout << "refused";
	else
	{
		std::cout << deposit << ";";
		Account::_amount += deposit;
		Account::_nbDeposits++;
		Account::_totalNbDeposits++;
		Account::_totalAmount += deposit;
		std::cout << "amount:" << Account::_amount << ";";
		std::cout << "nb_deposits:" << Account::_nbDeposits << std::endl;
	}
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();

	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal < 0 || withdrawal > Account::_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << withdrawal << ";";
		Account::_amount -= withdrawal;
		Account::_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << "amount:" << Account::_amount << ";";
		std::cout << "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
		return (true);
	}
}
int		Account::checkAmount( void ) const
{
	return (Account::_amount);
}
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();

	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "deposits:" << Account::_nbDeposits << ";";
	std::cout << "withdrawals:" << Account::_nbWithdrawals;
	std::cout << std::endl;
}
