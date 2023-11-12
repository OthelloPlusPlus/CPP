/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClassName.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 0000/00/00 00:00:00 by ohengelm      #+#    #+#                 */
/*   Updated: 0000/00/00 00:00:00 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClassName.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

ClassName::ClassName(void)
{
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "ClassName"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

ClassName::ClassName(const ClassName &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "ClassName"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

ClassName::~ClassName(void)
{
	std::cout	<< C_RED	<< "Deconstructor "
				<< C_RED	<< "ClassName"
				<< C_DRED	<< " called"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */


/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

ClassName	&ClassName::operator=(const ClassName &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
