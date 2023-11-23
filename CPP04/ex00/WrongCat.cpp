/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

WrongCat::WrongCat(void)
{
	std::cout	<< C_DGREEN	<< "The "
				<< C_GREEN	<< this->type
				<< C_DGREEN	<< " in unveiled to be a ";
	this->type = "Rat";
	std::cout	<< C_GREEN	<< this->type
				<< C_DGREEN	<< "."
				<< C_RESET	<< std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "WrongCat"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

WrongCat::~WrongCat(void)
{
	std::cout	<< C_DRED	<< "The wild "
				<< C_RED	<< this->type
				<< C_DRED	<< " is tjirping..."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	WrongCat::makeSound(void) const
{
	std::cout	<< "MEOW"	<< std::flush;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}
