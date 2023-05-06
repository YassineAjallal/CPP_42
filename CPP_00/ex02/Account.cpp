/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:14:44 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/06 19:16:58 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>



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
	std::cout << "getNbDeposits\n";
	return (0);
}
int	Account::getNbWithdrawals( void )
{
	std::cout << "getNbWithdrawals\n";
	return (0);
}
void Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}
Account::Account( int initial_deposit )
{
	Account::_accountIndex = Account::getNbAccounts();
	Account::_amount = initial_deposit;
	Account::_nbDeposits = Account::_totalNbDeposits;
	Account::_nbWithdrawals = Account::_totalNbWithdrawals;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts += 1;

	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created" << std::endl;
}
Account::~Account( void )
{
	// std::cout << "index:" << _accountIndex << ";";
	// std::cout << "amount" << _amount << ";";
	// std::cout << "closed" << std::endl;
}
void	Account::makeDeposit( int deposit )
{
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	std::cout << "deposits:" << Account::_nbDeposits << ";";
	std::cout << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	std::cout << "withdrawal" << std::endl;
	return (0);
}
int		Account::checkAmount( void ) const
{
	std::cout << "checkAmount\n";
	return 0;
}
void	Account::displayStatus( void ) const
{
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "deposits:" << Account::_nbDeposits << ";";
	std::cout << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
Account::makeDeposit(int);
Account::makeWithdrawal(int);
Account::displayAccountsInfos();
Account::Account(int);
Account::~Account();
Account::displayStatus() const;
*/

/*
displayAccountsInfos() ==> nb_acounts, total, deposits, with
*/

// The const keyword at the end of the function signature indicates that this member function does not modify any non-static data members of the Account class.
