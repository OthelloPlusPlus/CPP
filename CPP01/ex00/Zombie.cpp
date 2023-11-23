/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <iomanip>
// std::setw()

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Zombie::Zombie(void)
{
	std::cout	<< C_DGREEN	<< "Unnamed Zombie has risen from the grave."
				<< C_RESET	<< std::endl;
}

Zombie::Zombie(std::string name): name(name)
{
	std::cout	<< C_DGREEN	<< "Zombie "
				<< C_GREEN	<< this->name
				<< C_DGREEN	<< " has risen from the grave."
				<< C_RESET	<< std::endl;
}

Zombie::Zombie(const Zombie &src)
{
	*this = src;
	// std::cout	<< C_GREEN	<< "Zombie copy constructed"
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Zombie::~Zombie(void)
{
	std::cout	<< C_DRED	<< "Zombie "
				<< C_RED	<< this->name
				<< C_DRED	<< " starved due to lack of BraiiiiiiinnnzzzZ..."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Zombie::setName(std::string name)
{
	this->name = name;
	std::cout	<< C_DGREEN	<< "Zombie has been named "
				<< C_GREEN	<< this->name
				<< C_DGREEN	<< "."
				<< C_RESET	<< std::endl;
}

void	Zombie::announce(void)
{
	std::cout	<<	name
				<< ": BraiiiiiiinnnzzzZ..."
				<<	std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Zombie	&Zombie::operator=(const Zombie &src)
{
	this->name = src.name;
	return (*this);
}
