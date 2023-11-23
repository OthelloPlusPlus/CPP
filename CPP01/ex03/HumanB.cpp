/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

HumanB::HumanB(std::string new_name): \
	name(new_name), weapon(NULL)
{
	std::cout	<< C_DGREEN	<< "Unarmed HumanB "
				<< C_GREEN	<< this->name
				<< C_DGREEN	<< " has rolled initiative."
				<< C_RESET	<< std::endl;
}

HumanB::HumanB(const HumanB &src)
{
	this->name = src.name;
	if (src.weapon == NULL)
		this->weapon = NULL;
	else
		this->weapon = new Weapon(src.weapon->getType());
	std::cout	<< C_GREEN	<< "HumanB copy constructed"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

HumanB::~HumanB(void)
{
	std::cout	<< C_DRED	<< "HumanB "
				<< C_RED	<< this->name
				<< C_DRED	<< " fled."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	HumanB::attack(void)
{
	if(this->weapon)
		std::cout	<< C_ORANGE	<< this->name
					<< C_DORANGE	<< " attacks with their "
					<< C_ORANGE	<< this->weapon->getType()
					<< C_DORANGE	<< "."
					<< C_RESET	<< std::endl;
	else
		std::cout	<< C_ORANGE	<< this->name
					<< C_DORANGE	<< " has no weapon and cowers in fear!"
					<< C_RESET	<< std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
	std::cout	<< C_LGRAY	<< this->name
				<< C_DGRAY	<< " has equipped "
				<< C_LGRAY	<< this->weapon->getType()
				<< C_DGRAY	<< "."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

HumanB	&HumanB::operator=(const HumanB &src)
{
	this->name = src.name;
	this->weapon = src.weapon;
	return (*this);
}
