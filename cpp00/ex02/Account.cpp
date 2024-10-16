/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:48:33 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/16 15:48:34 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(){ return (_nbAccounts); }
int Account::getTotalAmount(){ return (_totalAmount); }
int Account::getNbDeposits(){ return (_totalNbDeposits); }
int Account::getNbWithdrawals(){ return (_totalNbWithdrawals); }

int		Account::checkAmount() const
{
	return (_amount);
}

Account::Account()
{
	Account::_displayTimestamp();
	_accountIndex = _nbAccounts;
	std::cout << "index:" << _accountIndex << ";amount:" << 0 << ";created\n";
	_amount = 0;
	_nbAccounts++;
}
Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();
	_accountIndex = _nbAccounts;
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created\n";
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}
Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed\n";
}

void	Account::_displayTimestamp()
{
	std::time_t timenow = time(NULL);
	struct tm datetime;

	datetime = *localtime(&timenow);
	std::cout << '[' << datetime.tm_year + 1900 
			<< std::setw(2) << std::setfill('0') << datetime.tm_mon + 1
			<< std::setw(2) << std::setfill('0') << datetime.tm_mday
			<< '_' 
			<< std::setw(2) << std::setfill('0') << datetime.tm_hour
			<< std::setw(2) << std::setfill('0') << datetime.tm_min
			<< std::setw(2) << std::setfill('0') << datetime.tm_sec << "] ";
}
void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:"
			<< getTotalAmount() << ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << ";p_amount:"
		<< checkAmount() << ";deposit:" << deposit << ";amount:"
		<< checkAmount() + deposit << ";nb_deposits:" << _nbDeposits << '\n';
	_amount += deposit;
}
bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
		<< checkAmount() << ";withdrawal:";
	if (_amount >= withdrawal)
	{
		_nbWithdrawals++;
		std::cout << withdrawal << ";amount:"
			<< checkAmount() - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << '\n';
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);
	}
	else
		std::cout << "refused\n";
	return (false);
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< checkAmount() << ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << '\n';
}
