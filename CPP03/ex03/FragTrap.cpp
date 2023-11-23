/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
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

FragTrap::FragTrap(std::string new_name): 
ClapTrap(new_name, FragTrap::defaultHP, FragTrap::defaultEP, FragTrap::defaultAD), excited(true)
{
	this->displayClassName(C_DCHRT, C_CHRT);
	this->setType("FragTrap");
	this->setHPCurrent(this->getHPMax());
	this->setEPCurrent(this->getEPMax());
	std::cout	<< C_DCHRT	<< "transformed into a "
				<< C_CHRT	<< this->getType()
				<< C_RESET	"\t\"Toss a coin to your witcher...\""
				<< C_RESET	<< std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src.getName())
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "FragTrap"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

FragTrap::~FragTrap(void)
{
	this->displayClassName(C_DRED, C_RED);
	std::cout	<< C_DRED	<< "\"Burn Butcher BURN!\""
				<< PRINT_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	FragTrap::highFivesGuys(void)
{
	this->displayClassName(C_RESET, C_ORANGE);
	if (this->excited == true)
	{
		std::cout	<< C_RESET	<< "cheers and tries to give a high five!"
					<< C_RESET	<< std::endl;
		this->excited = false;
	}
	else
		std::cout	<< C_RESET	<< "is left hanging..."
					<< C_RESET	<< std::endl;
}

void	FragTrap::displaySelf(void) const
{
	std::cout	<< PRINT_INFO	<< "Excited:"	<< this->excited	<< "\n"
				<< PRINT_RESET	<< std::flush;
}

void	FragTrap::displayInfo(void) const
{
	ClapTrap::displaySelf();
	FragTrap::displaySelf();
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	if (this == &src)
		return (*this);
	this->setType(src.getType());
	this->setHPMax(src.getHPMax());
	this->setHPCurrent(src.getHPCurrent());
	this->setEPMax(src.getEPMax());
	this->setEPCurrent(src.getEPCurrent());
	this->setAttackDamage(src.getAttackDamage());
	this->excited = src.excited;

	return (*this);
}
