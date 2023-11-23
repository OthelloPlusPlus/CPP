/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

WrongAnimal::WrongAnimal(void): type("Animal")
{
	std::cout	<< C_DGREEN	<< "A wild "
				<< C_GREEN	<< this->type
				<< C_DGREEN	<< " appeared!"
				<< C_RESET	<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "WrongAnimal"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

WrongAnimal::~WrongAnimal(void)
{
	std::cout	<< C_DRED	<< "The wild "
				<< C_RED	<< this->type
				<< C_DRED	<< " fled!"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	WrongAnimal::makeSound(void) const
{
	std::cout	<< "MOOOOOOOO"	<< std::flush;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}
