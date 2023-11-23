/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Base::Base(void)
{
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "Base"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

Base::Base(const Base &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "Base"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Base::~Base(void)
{
	std::cout	<< C_DRED	<< "Deconstructor "
				<< C_RED	<< "Base"
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

Base	&Base::operator=(const Base &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
