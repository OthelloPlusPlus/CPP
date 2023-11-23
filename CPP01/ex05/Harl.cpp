/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Harl::Harl(void)
{
	this->message[0] = "DEBUG";
	this->complaint[0] = &Harl::debug;
	this->message[1] = "INFO";
	this->complaint[1] = &Harl::info;
	this->message[2] = "WARNING";
	this->complaint[2] = &Harl::warning;
	this->message[3] = "ERROR";
	this->complaint[3] = &Harl::error;
	std::cout	<< C_GREEN	<< "Harl"
				<< C_DGREEN	<< " has entered the diner."
				<< C_RESET	<< std::endl;
}

Harl::Harl(const Harl &src)
{
	*this = src;
	std::cout	<< C_GREEN	<< "Harl"
				<< C_DGREEN	<< " copy constructed"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Harl::~Harl(void)
{
	std::cout	<< C_RED	<< "Harl"
				<< C_DRED	<< " left the diner."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Harl::debug(void)
{
	std::cout	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
				<< "I really do!"
				<< std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void	Harl::warning(void)
{
	std::cout	<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years whereas you started working here since last month."
				<< std::endl;
}

void	Harl::error(void)
{
	std::cout	<< "This is unacceptable! "
				<< "I want to speak to the manager now."
				<< std::endl;
}

void	Harl::grunting(void) const
{
	std::cout	<<	"What do you want from me?"
				<<	std::endl;
}

void	Harl::complain(std::string level)
{
	size_t	i;

	i = 0;
	while (i < sizeof(Harl::message) / sizeof(std::string) && \
		level.compare(this->message[i]) != 0)
		i++;
	if (i < sizeof(Harl::message) / sizeof(std::string) )
		(this->*complaint[i])();
	else
		this->grunting();
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Harl	&Harl::operator=(const Harl &src)
{
	size_t	i;

	i = 0;
	while (i < sizeof(Harl::message) / sizeof(std::string))
	{
		this->message[i] = src.message[i];
		this->complaint[i] = src.complaint[i];
		i++;
	}
	return (*this);
}
