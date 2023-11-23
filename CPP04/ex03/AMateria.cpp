/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

AMateria::AMateria(std::string const &type): type(type)
{
	// std::cout	<< C_DGREEN	<< "Arcane energy "
	// 			<< C_GREEN	<< "AMateria"
	// 			<< C_DGREEN	<< " is accumulating."
	// 			<< C_RESET	<< std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
	// std::cout	<< C_DGREEN	<< "Copy constructor "
	// 			<< C_GREEN	<< "AMateria"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

AMateria::~AMateria(void)
{
	// std::cout	<< C_DRED	<< "Arcane energy "
	// 			<< C_RED	<< "AMateria"
	// 			<< C_DRED	<< " dissipated."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

std::string	const	&AMateria::getType(void) const
{
	return (this->type);
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

AMateria	&AMateria::operator=(const AMateria &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
