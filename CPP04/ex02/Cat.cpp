/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Cat::Cat(void)
{
	std::cout	<< C_DGREEN	<< "The "
				<< C_GREEN	<< this->type
				<< C_DGREEN	<< " in unveiled to be a ";
	this->type = "Cat";
	std::cout	<< C_GREEN	<< this->type
				<< C_DGREEN	<< "."
				<< C_RESET	<< std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "Cat"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Cat::~Cat(void)
{
	std::cout	<< C_DRED	<< "The wild "
				<< C_RED	<< this->type;
	delete this->brain;
	std::cout	<< C_DRED	<< "The wild "
				<< C_RED	<< this->type
				<< C_DRED	<< " is hissing..."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Cat::makeSound(void) const
{
	std::cout	<< "MEOW"	<< std::flush;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Cat	&Cat::operator=(const Cat &src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	this->brain = new Brain;
	return (*this);
}
