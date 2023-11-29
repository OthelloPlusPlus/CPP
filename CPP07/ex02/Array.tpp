/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 15:42:35 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/11/29 15:42:35 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

ARRAY_TEMPLATE
Array<T>::Array(void): n(0), value(NULL)
{
	// std::cout	<< C_DGREEN	<< "Default constructor "
	// 			<< C_GREEN	<< "Array"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

ARRAY_TEMPLATE
Array<T>::Array(unsigned int n): n(n), value(NULL)
{
	this->value = new T[this->n];
	// std::cout	<< C_DGREEN	<< "Default constructor "
	// 			<< C_GREEN	<< "Array(n)"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

ARRAY_TEMPLATE
Array<T>::Array(const Array &src): n(src.size()), value(NULL)
{
	*this = src;
	// std::cout	<< C_DGREEN	<< "Copy constructor "
	// 			<< C_GREEN	<< "Array"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

ARRAY_TEMPLATE
Array<T>::~Array(void)
{
	delete[] this->value;
	// std::cout	<< C_RED	<< "Deconstructor "
	// 			<< C_RED	<< "Array"
	// 			<< C_DRED	<< " called"
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

ARRAY_TEMPLATE
unsigned int	Array<T>::size(void) const
{
	return (this->n);
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

ARRAY_TEMPLATE
Array<T>	&Array<T>::operator=(const Array &src)
{
	if (this == &src)
		return (*this);
	this->n = src.size();
	delete[] this->value;
	this->value = new T[this->n];
	for (unsigned int i = 0; i < this->n; ++i)
		this->value[i] = src[i];
	return (*this);
}

ARRAY_TEMPLATE
T	&Array<T>::operator[](unsigned int i) const
{
	if (i >= this->n)
		throw (std::out_of_range("Invalid index"));
	return (this->value[i]);
}
