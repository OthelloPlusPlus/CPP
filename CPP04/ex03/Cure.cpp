/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Cure::Cure(void): AMateria("cure")
{
	// std::cout	<< C_DGREEN	<< "The spell "
	// 			<< C_GREEN	<< "Cure"
	// 			<< C_DGREEN	<< " has formed."
	// 			<< C_RESET	<< std::endl;
}

Cure::Cure(const Cure &src): AMateria("cure")
{
	*this = src;
	// std::cout	<< C_DGREEN	<< "Copy constructor "
	// 			<< C_GREEN	<< "Cure"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Cure::~Cure(void)
{
	// std::cout	<< C_DRED	<< "The spell "
	// 			<< C_RED	<< "Cure"
	// 			<< C_DRED	<< " was lost."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Cure::cast(std::string user, std::string target)
{
	std::cout	<< C_RESET	<< "* "
				<< C_ORANGE	<< user
				<< C_RESET	<< " heals "
				<< C_ORANGE	<< target	<< "'s"
				<< C_RESET	<< " wounds *"
				<< std::endl;
}

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Cure	&Cure::operator=(const Cure &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
