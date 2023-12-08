/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 19:20:43 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/08 19:20:43 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

PmergeMe::PmergeMe(void)
{
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "PmergeMe"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "PmergeMe"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

PmergeMe::~PmergeMe(void)
{
	std::cout	<< C_RED	<< "Deconstructor "
				<< C_RED	<< "PmergeMe"
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

PmergeMe	&PmergeMe::operator=(const PmergeMe &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
