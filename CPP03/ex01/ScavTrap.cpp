/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
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

ScavTrap::ScavTrap(std::string new_name): 
	ClapTrap(new_name, ScavTrap::defaultHP, ScavTrap::defaultEP, ScavTrap::defaultAD), mode(false)
{
	this->displayClassName(C_DCHRT, C_CHRT);
	this->setType("ScavTrap");
	this->setHPCurrent(this->getHPMax());
	this->setEPCurrent(this->getEPMax());
	std::cout	<< C_DCHRT	<< "transformed into a "
				<< C_CHRT	<< this->getType()
				<< C_RESET	"\tDrank a potion"
				<< C_RESET	<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src.getName())
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "ScavTrap"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

ScavTrap::~ScavTrap(void)
{
	this->displayClassName(C_DRED, C_RED);
	std::cout	<< C_DRED	<< "the potion wore off..."
				<< PRINT_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	ScavTrap::guardGate(void)
{
	this->displayClassName(C_RESET, C_ORANGE);
	if (this->mode == true)
	{
		this->mode = false;
		std::cout	<< "is no longer in Gate Keeper Mode."
					<< std::endl;
	}
	else
	{
		this->mode = true;
		std::cout	<< "is now in Gate Keeper Mode."
					<< std::endl;
	}
}

void	ScavTrap::attack(const std::string &target)
{
	this->displayClassName(C_RESET, C_ORANGE);
	if (this->getHPCurrent() <= 0)
	{
		std::cout	<< C_DRED	<< "is to dead to attack..."
					<< C_RESET	<< std::endl;
		return ;
	}
	if (this->getEPCurrent() <= 0)
	{
		std::cout	<< C_DRED	<< "is to tired to attack..."
					<< C_DRED	<< std::endl;
		return ;
	}
	this->setEPCurrent(this->getEPCurrent() - 1);
	std::cout	<< "attacks "
				<< C_ORANGE	<< target
				<< C_RESET	<< " with magic, causing "
				<< C_YELLOW	<< this->getAttackDamage()
				<< C_RESET	<< " points of damage!"
				<< std::endl;
}

void	ScavTrap::displaySelf(void) const
{
	std::cout	<< PRINT_INFO	<< "Mode:"	<< this->mode	<< "\n"
				<< PRINT_RESET	<< std::flush;
}

void	ScavTrap::displayInfo(void) const
{
	ClapTrap::displaySelf();
	ScavTrap::displaySelf();
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	if (this == &src)
		return (*this);
	this->setType(src.getType());
	this->setHPMax(src.getHPMax());
	this->setHPCurrent(src.getHPCurrent());
	this->setEPMax(src.getEPMax());
	this->setEPCurrent(src.getEPCurrent());
	this->setAttackDamage(src.getAttackDamage());
	this->mode = src.mode;

	return (*this);
}
