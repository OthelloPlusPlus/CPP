/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

// Serializer::Serializer(void)
// {
// 	std::cout	<< C_DGREEN	<< "Default constructor "
// 				<< C_GREEN	<< "Serializer"
// 				<< C_DGREEN	<< " called."
// 				<< C_RESET	<< std::endl;
// }

// Serializer::Serializer(const Serializer &src)
// {
// 	*this = src;
// 	std::cout	<< C_DGREEN	<< "Copy constructor "
// 				<< C_GREEN	<< "Serializer"
// 				<< C_DGREEN	<< " called."
// 				<< C_RESET	<< std::endl;
// }

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

// Serializer::~Serializer(void)
// {
// 	std::cout	<< C_DRED	<< "Deconstructor "
// 				<< C_RED	<< "Serializer"
// 				<< C_DRED	<< " called"
// 				<< C_RESET	<< std::endl;
// }

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

// Serializer	&Serializer::operator=(const Serializer &src)
// {
// 	if (this == &src)
// 		return (*this);

// 	return (*this);
// }
