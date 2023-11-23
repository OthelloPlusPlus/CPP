/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Point::Point(void): x(0), y(0)
{
	// std::cout	<< C_DGREEN	<< "Default constructor "
	// 			<< C_GREEN	<< "Point"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

Point::Point(const float x, const float y): x(x), y(y)
{
	// std::cout	<< C_DGREEN	<< "Default constructor "
	// 			<< C_GREEN	<< "Point"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

Point::Point(const Point &src): x(src.x), y(src.y)
{
	*this = src;
	// std::cout	<< C_DGREEN	<< "Copy constructor "
	// 			<< C_GREEN	<< "Point"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Point::~Point(void)
{
	// std::cout	<< C_RED	<< "Deconstructor "
	// 			<< C_RED	<< "Point"
	// 			<< C_DRED	<< " called"
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

float	Point::getX(void) const
{
	return (this->x.toFloat());
}

float	Point::getY(void) const
{
	return (this->y.toFloat());
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Point	&Point::operator=(const Point &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
