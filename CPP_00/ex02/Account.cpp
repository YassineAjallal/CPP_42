/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:14:44 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/10 14:36:59 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

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

void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
	Account::_accountIndex = Account::getNbAccounts();
	Account::_amount = initial_deposit;
	Account::_totalAmount += Account::_amount;
	Account::_nbAccounts += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	Account::_amount = Account::_amount + deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "nb_deposits:" << Account::_nbDeposits << std::endl;
	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_amount = Account::_amount - withdrawal;
	Account::_displayTimestamp();
	if (!checkAmount())
	{
		Account::_amount = Account::_amount + withdrawal;
		std::cout << "index:" << Account::_accountIndex << ";";
		std::cout << "p_amount:" << Account::_amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return (0);
	}
	Account::_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount + withdrawal<< ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
	return (1);
}

int		Account::checkAmount( void ) const
{
	if (Account::_amount < 0)
		return 0;
	else
		return (1);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "deposits:" << Account::_nbDeposits << ";";
	std::cout << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t currentTime = std::time(nullptr);
    std::tm* currentDate = std::localtime(&currentTime);
    
    int year = currentDate->tm_year + 1900; 
    int month = currentDate->tm_mon + 1;
    int day = currentDate->tm_mday;
	int hour = currentDate->tm_hour;
	int min =  currentDate->tm_min;
	int sec = currentDate->tm_sec;

    std::cout << "[";
	// print date;
	std::cout << year;
	month < 10 ? std::cout << "0" << month : std::cout << month;
	day < 10 ? std::cout << "0" << day : std::cout << day;
	std::cout << "_";
	// print time
	hour < 10 ? std::cout << "0" << hour : std::cout  << hour;
	min < 10 ? std::cout << "0" << min : std::cout  << min;
	sec < 10 ? std::cout << "0" << sec : std::cout  << sec;
	std::cout <<  "] ";
}

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;