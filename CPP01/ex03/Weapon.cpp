/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Weapon::Weapon(std::string new_type): type(new_type)
{
	std::cout	<< C_DGREEN	<< "Weapon "
				<< C_GREEN	<< this->type
				<< C_DGREEN	<< " has been forged."
				<< C_RESET	<< std::endl;
}

Weapon::Weapon(const Weapon &src)
{
	this->type = src.type;
	*this = src;
	// std::cout	<< C_GREEN	<< "Weapon copy constructed"
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Weapon::~Weapon(void)
{
	std::cout	<< C_DRED	<< "Weapon "
				<< C_RED	<< this->type
				<< C_DRED	<< " broke."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

const std::string	&Weapon::getType(void)
{
	return (this->type);
}

void				Weapon::setType(std::string new_type)
{
	std::cout	<< C_LGRAY	<< this->type;
	this->type = new_type;
	std::cout	<< C_DGRAY	<< " has changed into "
				<< C_LGRAY	<< this->type
				<< C_DGRAY	<< "."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Weapon	&Weapon::operator=(const Weapon &src)
{
	this->type = src.type;
	return (*this);
}
