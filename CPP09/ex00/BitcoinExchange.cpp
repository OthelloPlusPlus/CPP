/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 19:19:37 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/08 19:19:37 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void)
{
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "BitcoinExchange"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "BitcoinExchange"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout	<< C_RED	<< "Deconstructor "
				<< C_RED	<< "BitcoinExchange"
				<< C_DRED	<< " called"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */


/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
