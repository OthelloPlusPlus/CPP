/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Dog::Dog(void)
{
	std::cout	<< C_DGREEN	<< "The "
				<< C_GREEN	<< this->type
				<< C_DGREEN	<< " in unveiled to be a ";
	this->type = "Dog";
	std::cout	<< C_GREEN	<< this->type
				<< C_DGREEN	<< "."
				<< C_RESET	<< std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "Dog"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Dog::~Dog(void)
{
	std::cout	<< C_DRED	<< "The wild "
				<< C_RED	<< this->type;
	delete this->brain;
	std::cout	<< C_DRED	<< "The wild "
				<< C_RED	<< this->type
				<< C_DRED	<< " is growling..."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Dog::makeSound(void) const
{
	std::cout	<< "WOOF"	<< std::flush;
}

void	Dog::displayAddress(void) const
{
	std::cout	<< this	<< "\t"	<< this->type	<< "\t"
				<< this->brain	<< "\t"	<< "brain"
				<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Dog	&Dog::operator=(const Dog &src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	this->brain = new Brain;
	return (*this);
}
