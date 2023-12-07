/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 15:56:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/07 15:56:13 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <cstdlib>
// std::rand()
#include <algorithm>
// std::min_element
// std::max_element
#include <limits>
// std::numeric_limits

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Span::Span(unsigned int size): maxSize(size)
{
	// std::cout	<< C_DGREEN	<< "Default constructor "
	// 			<< C_GREEN	<< "Span"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

Span::Span(const Span &src)
{
	*this = src;
	// std::cout	<< C_DGREEN	<< "Copy constructor "
	// 			<< C_GREEN	<< "Span"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Span::~Span(void)
{
	// std::cout	<< C_RED	<< "Deconstructor "
	// 			<< C_RED	<< "Span"
	// 			<< C_DRED	<< " called"
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Span::addNumber(int value)
{
	if (this->span.size() >= this->maxSize)
		throw(std::overflow_error("Span is full"));
	this->span.push_back(value);
	// ++this->span.size();
}

void	Span::addNumbers(unsigned int count)
{
	if (this->span.size() >= this->maxSize)
		throw(std::overflow_error("Span is full"));
	try
	{
		for (unsigned int i = 0; i < count; ++i)
			this->addNumber(std::rand());
	}
	catch(const std::exception &e)
	{}	
}

long	Span::shortestSpan(void) const
{
	if (this->span.size() < 2)
		throw (std::range_error(std::string("Not enough numbers for ") + __func__));
	std::vector<int>	cpy(this->span);
	long				shortest = std::numeric_limits<long>::max();

	std::sort(cpy.begin(), cpy.end());
	for (std::vector<int>::iterator i = cpy.begin(); i + 1 != cpy.end(); ++i)
	{
		long	temp = *(i + 1) - *i;
		if (temp < shortest)
		{
			// std::cout	<<C_CYAN<< temp <<" = "<<*(i + 1)<<" - "<<*i<<C_RESET<<std::endl;
			shortest = temp;
		}
	}
	return (shortest);
}

long	Span::longestSpan(void) const
{
	if (this->span.size() < 2)
		throw (std::range_error(std::string("Not enough numbers for ") + __func__));
	return (*std::max_element(this->span.begin(), this->span.end()) - \
			*std::min_element(this->span.begin(), this->span.end()));
}

void	Span::printSpan(void)
{
	for (std::vector<int>::iterator i = this->span.begin(); i != this->span.end(); ++i)
		std::cout	<< *i	<< ' ';
	std::cout	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Span	&Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	this->maxSize = src.maxSize;
	this->span = src.span;
	return (*this);
}
