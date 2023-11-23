/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Ice::Ice(void): AMateria("ice")
{
	// std::cout	<< C_DGREEN	<< "The spell "
	// 			<< C_GREEN	<< "Ice"
	// 			<< C_DGREEN	<< " has formed."
	// 			<< C_RESET	<< std::endl;
}

Ice::Ice(const Ice &src): AMateria("ice")
{
	*this = src;
	// std::cout	<< C_DGREEN	<< "Copy constructor "
	// 			<< C_GREEN	<< "Ice"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Ice::~Ice(void)
{
	// std::cout	<< C_DRED	<< "The spell "
	// 			<< C_RED	<< "Ice"
	// 			<< C_DRED	<< " was lost."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Ice::cast(std::string user, std::string target)
{
	std::cout	<< C_RESET	<< "* "
				<< C_ORANGE	<< user
				<< C_RESET	<< " shoots an ice bolt at "
				<< C_ORANGE	<< target
				<< C_RESET	<< " *"
				<< std::endl;
}

AMateria	*Ice::clone(void) const
{
	return (new Ice());
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Ice	&Ice::operator=(const Ice &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
