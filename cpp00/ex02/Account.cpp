/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:34:02 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/11 12:46:44 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(NULL);
	std::tm *tm   = std::localtime(&t);
	char buf[20];
	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", tm);
	std::cout << "[" << buf << "] ";
}

/*	Constructor: initialize account with index, amount and counters,
	update global stats, and display creation log with timestamp.*/

Account::Account( int initial_deposit ) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/* Destructor: display account closure with timestamp (no update of globals). */

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/* Getters for the Account class */

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

/* Display global account information with timestamp. */

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/*	add amount to account and global totals, update counters,
	and display operation log.*/

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"  << _amount << ";deposit:" << deposit;
	_amount          += deposit;
	_totalAmount     += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

/*	withdraw if possible, update account and global stats,
	display result, and return success status.*/

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

/* another getter returns current account balance (read-only) */

int Account::checkAmount( void ) const
{
	return (_amount);
}