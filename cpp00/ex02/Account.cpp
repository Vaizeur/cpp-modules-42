/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:00:05 by odanyliu          #+#    #+#             */
/*   Updated: 2026/03/27 21:12:35 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void displayTimeFormat(int value, int len);

int Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int Account::getTotalAmount() {
	return (_totalAmount);
}

int Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout 
		<< " accounts:" << _nbAccounts 
		<< ";total:" << _totalAmount 
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout 
		<< " index:" << _accountIndex 
		<< ";amount:" << _amount 
		<< ";created" 
	<< std::endl;
}

void Account::_displayTimestamp( void )
{
	//std::cout << "[1992 0104_091532]";
	time_t ctime = std::time(NULL);
	struct tm ntime = *std::localtime(&ctime);
	
	std::cout << "[" ;	
	std::cout << ntime.tm_year + 1900;
	displayTimeFormat(ntime.tm_mon + 1, 2);
	displayTimeFormat(ntime.tm_mday, 2);
	std::cout << "_" ;
	displayTimeFormat(ntime.tm_hour, 2);
	displayTimeFormat(ntime.tm_min, 2);
	displayTimeFormat(ntime.tm_sec, 2);
	std::cout << "]" ;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_displayTimestamp();
	std::cout 
		<< " index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits 
	<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout 
			<< " index:" << _accountIndex
			<< ";p_amount:" << checkAmount()
			<< ";withdrawal:refused"
		<< std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_displayTimestamp();
	std::cout 
		<< " index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << _nbWithdrawals 
	<< std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount(void) const {
	return (_amount);
}

void Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout 
		<< " index:" << _accountIndex
		<< ";amount:" << checkAmount()
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;		
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout 
		<< " index:" << _accountIndex 
		<< ";amount:" << checkAmount()
		<< ";closed" 
	<< std::endl;
}

void displayTimeFormat(int value, int len)
{
	std::cout << std::setfill('0') << std::setw(len) << value;
}
