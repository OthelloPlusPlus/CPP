/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 17:39:00 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 16:10:39 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
//std::
#include <iomanip>
//std::setw std::setfill

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Account::Account(void)
{
}

Account::Account( int initial_deposit ): _amount(initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout	<< "index:"	<< this->_accountIndex	<< ";"
				<< "amount:"	<< this->_amount	<< ";"
				<< "created"
				<< std::endl;
}

// Account::Account(const Account &src)
// {
// 	*this = src;
// }

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Account::~Account(void)
{
	_displayTimestamp();
	Account::_nbAccounts--;
	std::cout	<< "index:"	<< this->_accountIndex	<< ";"
				<< "amount:"	<< this->_amount	<< ";"
				<< "closed"
				<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */


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
		return (_totalNbDeposits);
	}
	
	int	Account::getNbWithdrawals( void )
	{
		return (_totalNbWithdrawals);
	}
	
	void	Account::displayAccountsInfos( void )
	{
		_displayTimestamp();
		std::cout	<< "accounts:"	<< Account::_nbAccounts	<< ";"
					<< "total:"	<< Account::_totalAmount	<< ";"
					<< "deposits:"	<< Account::_totalNbDeposits	<< ";"
					<< "withdrawals:"	<< Account::_totalNbWithdrawals
					<< std::endl;
	}
	
	void	Account::makeDeposit( int deposit )
	{
		int	p_amount;

		p_amount = this->_amount;
		if (deposit <= 0)
			return ;
		this->_amount += deposit;
		Account::_totalAmount += deposit;
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
		
		_displayTimestamp();
		std::cout	<< "index:"	<< this->_accountIndex	<< ";"
					<< "p_amount:"	<< p_amount	<< ";"
					<< "deposit:"	<< deposit	<< ";"
					<< "amount:"	<< this->_amount	<< ";"
					<< "nb_deposits:"	<< this->_nbDeposits
					<< std::endl;
	}
	
	bool	Account::makeWithdrawal( int withdrawal )
	{
		bool	status;
		int		p_amount;
	
		status = true;
		p_amount = this->_amount;
		if (p_amount < withdrawal || withdrawal < 0)
			status = false;
		if (status == true)
		{
			this->_amount -= withdrawal;
			Account::_totalAmount -= withdrawal;
			this->_nbWithdrawals++;
			Account::_totalNbWithdrawals++;
		}

		_displayTimestamp();
		std::cout	<< "index:"	<< this->_accountIndex	<< ";"
					<< "p_amount:"	<< p_amount	<< ";"
					<< "withdrawal:";
		if (status == false)
			std::cout	<< "refused";
		else
		{
			std::cout	<< withdrawal	<< ";"
						<< "amount:"	<< this->_amount	<< ";"
						<< "nb_withdrawals:"	<< this->_nbWithdrawals;
		}
		std::cout	<< std::endl;
		return (status);
	}
	
	int		Account::checkAmount( void ) const
	{
		return (this->_amount);
	}
	
	void	Account::displayStatus( void ) const
	{
		_displayTimestamp();
		std::cout	<< "index:"	<< this->_accountIndex	<< ";"
					<< "amount:"	<< this->_amount	<< ";"
					<< "deposits:"	<< this->_nbDeposits	<< ";"
					<< "withdrawals:"	<< this->_nbWithdrawals
					<< std::endl;
	}
	
	void	Account::_displayTimestamp( void )
	{
		time_t	now;
		tm		*ltm;

		now = std::time(0);
		ltm = localtime(&now);
		std::cout << "["\
					<< ltm->tm_year + 1900 \
					<< std::setw(2) << std::setfill('0') << ltm->tm_mon + 1\
					<< std::setw(2) << std::setfill('0') << ltm->tm_mday\
					<< "_"\
					<< std::setw(2) << std::setfill('0') << ltm->tm_hour\
					<< std::setw(2) << std::setfill('0') << ltm->tm_min\
					<< std::setw(2) << std::setfill('0') << ltm->tm_sec\
					<< "] ";
	}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

// Account	&Account::operator=(const Account &src)
// {
// 	this->_accountIndex = src._accountIndex;
// 	this->_amount = src._amount;
// 	this->_nbDeposits = src._nbDeposits;
// 	this->_nbWithdrawals = src._nbWithdrawals;
// 	return (*this);
// }
