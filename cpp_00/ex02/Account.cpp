/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:38:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/27 23:06:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
:	_accountIndex(Account::_nbAccounts) , _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout 	<< "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";created"
				<< std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout 	<< "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";closed"
				<< std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:"
				<< getNbAccounts()
				<< ";total:"
				<< getTotalAmount()
				<< ";deposits:"
				<< getNbDeposits()
				<< ";withdrawals:"
				<< getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount {_amount};

	_displayTimestamp();
	_amount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout	<< "index:"
				<< _accountIndex
				<< ";p_amount:"
				<< p_amount
				<< ";deposit:"
				<< deposit
				<< ";amount:"
				<< _amount
				<< ";nb_deposits:"
				<< _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount {_amount};

	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";p_amount:"
				<< p_amount
				<< ";withdrawal:";
	if (checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout	<< withdrawal
					<< ";amount:"
					<< _amount
					<< ";nb_withdrawals:"
					<< _nbWithdrawals
					<< std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";deposits:"
				<< _nbDeposits
				<< ";withdrawals:"
				<< _nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t timestamp;
	struct tm datetime;

	time(&timestamp);
	datetime = *localtime(&timestamp);
	std::cout 	<< "["
				<< datetime.tm_year + 1900
				<< datetime.tm_mon + 1
				<< datetime.tm_mday
				<< "_"
				<< datetime.tm_hour + 1
				<< datetime.tm_min
				<< datetime.tm_sec
				<< "] ";
}
