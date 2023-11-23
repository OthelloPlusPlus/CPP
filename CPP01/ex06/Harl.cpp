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
	this->message[1] = "INFO";
	this->message[2] = "WARNING";
	this->message[3] = "ERROR";
	// std::cout	<< C_GREEN	<< "Harl"
	// 			<< C_DGREEN	<< " has entered the diner."
	// 			<< C_RESET	<< std::endl;
}

Harl::Harl(const Harl &src)
{
	*this = src;
	// std::cout	<< C_GREEN	<< "Harl"
	// 			<< C_DGREEN	<< " copy constructed"
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Harl::~Harl(void)
{
	// std::cout	<< C_RED	<< "Harl"
	// 			<< C_DRED	<< " left the diner."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Harl::debug(void)
{
	std::cout	<<	"[ " C_GREEN "DEBUG" C_RESET " ]\n"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
				<< "I really do!\n"
				<< std::endl;
}

void	Harl::info(void)
{
	std::cout	<<	"[ " C_YELLOW "INFO" C_RESET " ]\n"
				<< "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger!\n"
				<< "If you did, I wouldn’t be asking for more!\n"
				<< std::endl;
}

void	Harl::warning(void)
{
	std::cout	<<	"[ " C_ORANGE "WARNING" C_RESET " ]\n"
				<< "I think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years whereas you started working here since last month.\n"
				<< std::endl;
}

void	Harl::error(void)
{
	std::cout	<<	"[ " C_RED "ERROR" C_RESET " ]\n"
				<< "This is unacceptable!\n"
				<< "I want to speak to the manager now.\n"
				<< std::endl;
}

void	Harl::grunting(void) const
{
	std::cout	<<	"[ " C_GRAY "Probably complaining about insignificant problems" C_RESET " ]"
				<<	std::endl;
}

size_t		Harl::complainIndex(std::string level)
{
	size_t	i;

	i = 0;
	while (i < sizeof(message) / sizeof(std::string) && \
			level != this->message[i])
		i++;
	return (i);
}

void	Harl::complain(std::string level)
{
	size_t	i;

	i = this->complainIndex(level);
	switch(i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			this->grunting();
	}
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
		i++;
	}
	return (*this);
}
