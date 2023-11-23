/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Animal::Animal(void): type("Animal")
{
	std::cout	<< C_DGREEN	<< "A wild "
				<< C_GREEN	<< this->type
				<< C_DGREEN	<< " appeared!"
				<< C_RESET	<< std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "Animal"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Animal::~Animal(void)
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

void	Animal::makeSound(void) const
{
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::displayAddress(void) const
{
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Animal	&Animal::operator=(const Animal &src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}
