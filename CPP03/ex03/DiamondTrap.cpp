/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
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

DiamondTrap::DiamondTrap(std::string new_name): 
	ClapTrap(new_name + "_clap_name", DiamondTrap::defaultHP, DiamondTrap::defaultEP, DiamondTrap::defaultAD), ScavTrap(""), FragTrap(""), name(new_name)
{
	this->displayClassName(C_DCHRT, C_CHRT);
	this->setType("DiamondTrap");
	this->setHPCurrent(this->getHPMax());
	this->setEPCurrent(this->getEPMax());
	std::cout	<< C_DCHRT	<< "transformed into a "
				<< C_CHRT	<< this->getType()
				<< C_RESET	"\t\"No. I will flee no more.\""
				<< C_RESET	<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): 
	ClapTrap(this->getName(), DiamondTrap::defaultHP, DiamondTrap::defaultEP, DiamondTrap::defaultAD), ScavTrap(""), FragTrap("")
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "DiamondTrap"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

DiamondTrap::~DiamondTrap(void)
{
	this->displayClassName(C_DRED, C_RED);
	std::cout	<< C_DRED "\"There's time to stand still and there's time to keep moving.\""
				<< PRINT_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	DiamondTrap::whoAmI(void)
{
	std::cout	<< C_RESET	<< this->getType() + " "
				<< C_CYAN	<< this->name	<< "\n"
				<< C_RESET	<< "\t\"Everybody has plans for me...\"\n"
				<< C_RESET	<< "\t\"But who am I and what do I want?\"\n"
				<< C_RESET	<< "\t\"Am I "
				<< C_LCYAN	<< this->name	
				<< C_RESET	<< ", or am I "
				<< C_DCYAN	<< ClapTrap::getName()
				<< C_RESET	<< "?\""
				<< std::endl;
}

void	DiamondTrap::displaySelf(void) const
{
	std::cout	<< PRINT_INFO	<< "Alias:"	<< this->name	<< "\n"
				<< PRINT_RESET	<< std::flush;
}

void	DiamondTrap::displayInfo(void) const
{
	ClapTrap::displaySelf();
	ScavTrap::displaySelf();
	FragTrap::displaySelf();
	DiamondTrap::displaySelf();
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
