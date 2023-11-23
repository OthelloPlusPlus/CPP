/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

HumanA::HumanA(std::string new_name, Weapon &new_weapon): \
	name(new_name), weapon(new_weapon)
{
	std::cout	<< C_DGREEN	<< "HumanA "
				<< C_GREEN	<< this->name
				<< C_DGREEN << " wielding "
				<< C_GREEN	<< this->weapon.getType()
				<< C_DGREEN	<< " has rolled initiative."
				<< C_RESET	<< std::endl;
}

HumanA::HumanA(const HumanA &src): name(src.name), weapon(src.weapon)
{
	std::cout	<< C_GREEN	<< "HumanA copy constructed"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

HumanA::~HumanA(void)
{
	std::cout	<< C_DRED	<< "HumanA "
				<< C_RED	<< this->name
				<< C_DRED	<< " fled."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	HumanA::attack(void)
{
	std::cout	<< C_ORANGE	<< this->name
				<< C_DORANGE	<< " attacks with their "
				<< C_ORANGE	<< this->weapon.getType()
				<< C_DORANGE	<< "."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

HumanA	&HumanA::operator=(const HumanA &src)
{
	this->name = src.name;
	this->weapon = src.weapon;
	return (*this);
}
