/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
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

ClapTrap::ClapTrap(std::string const new_name): 
	type("ClapTrap"), name(new_name), HPMax(ClapTrap::defaultHP), EPMax(ClapTrap::defaultEP), AttackDamage(ClapTrap::defaultAD)
{
	this->HPCurrent = this->HPMax;
	this->EPCurrent = this->EPMax;
	this->displayClassName(C_DCHRT, C_CHRT);
	std::cout	<< C_DCHRT "rolled initiative!!!"
				<< PRINT_RESET	<< std::endl;
}

ClapTrap::ClapTrap(std::string const new_name, const unsigned new_HP, const unsigned new_EP, const unsigned new_AD): 
	type("ClapTrap"), name(new_name), HPMax(new_HP), EPMax(new_EP), AttackDamage(new_AD)
{
	this->HPCurrent = this->HPMax;
	this->EPCurrent = this->EPMax;
	this->displayClassName(C_DCHRT, C_CHRT);
	std::cout	<< C_DCHRT "rolled initiative!!!"
				<< PRINT_RESET	<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "ClapTrap"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

ClapTrap::~ClapTrap(void)
{
	this->displayClassName(C_DRED, C_RED);
	std::cout	<< C_DRED	<< "has left the battle..."
				<< PRINT_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	ClapTrap::attack(const std::string &target)
{
	this->displayClassName(C_RESET, C_ORANGE);
	if (this->HPCurrent <= 0)
	{
		std::cout	<< C_DRED	<< "is to dead to attack..."
					<< C_RESET	<< std::endl;
		return ;
	}
	if (this->EPCurrent <= 0)
	{
		std::cout	<< C_DRED	<< "is to tired to attack..."
					<< C_DRED	<< std::endl;
		return ;
	}
	this->EPCurrent--;
	std::cout	<< "attacks "
				<< C_ORANGE	<< target
				<< C_RESET	<< ", causing "
				<< C_YELLOW	<< this->AttackDamage
				<< C_RESET	<< " points of damage!"
				<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	damage;
	unsigned int	overkill;

	this->displayClassName(C_RESET, C_ORANGE);
	if (this->HPCurrent <= 0)
	{
		std::cout	<< "is to dead to be damaged..."
					<< std::endl;
		return ;
	}
	if (amount > this->HPCurrent)
		damage = this->HPCurrent;
	else
		damage = amount;
	overkill = amount - damage;
	this->HPCurrent -= damage;
	std::cout	<< "took "
				<< C_YELLOW	<< damage;
	if (overkill > 0)
		std::cout	<< "("
					<< overkill
					<< " overkill)";
	std::cout	<< C_RESET	<< " damage!"
				<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	heal;
	unsigned int	overheal;

	this->displayClassName(C_RESET, C_ORANGE);
	if (this->EPCurrent <= 0)
	{
		std::cout	<< C_DRED	<< "is to tired to heal..."
					<< C_RESET	<< std::endl;
		return ;
	}
	if (this->HPCurrent + amount > this->HPMax)
		heal = this->HPMax - this->HPCurrent;
	else
		heal = amount;
	overheal = amount - heal;
	if (this->HPCurrent == 0)
	{
		std::cout	<< C_GOLD	<< "has been resurected!"
					<< C_RESET	<< std::endl;
	}
	else
	{
		std::cout	<< "has been healed for "
					<< C_CHRT	<< heal;
		if (overheal > 0)
			std::cout	<< "("
						<< overheal
						<< " overhealing)";
		std::cout	<< C_RESET	<< " hit points!"
					<< std::endl;
	}
	this->EPCurrent--;
	this->HPCurrent += heal;
}

void	ClapTrap::displayClassName(std::string col1, std::string col2) const
{
	std::cout	<< std::setw(col1.length() + col2.length() + 12 + 15)	<< std::left	
				<< col1	+ this->type + " " + col2 + this->name
				<< PRINT_RESET	<< std::flush;
}

void	ClapTrap::displaySelf(void) const
{
	std::cout	<< PRINT_INFO	<< "Type:"	<< this->type	<< "\n"
				<< PRINT_INFO	<< "Name:"	<< this->name	<< "\n"
				<< PRINT_INFO	<< "Hp:"	<< this->HPCurrent	<< "/"	<< this->HPMax	<< "\n"
				<< PRINT_INFO	<< "Energy:"	<< this->EPCurrent	<< "/"	<< this->EPMax	<< "\n"
				<< PRINT_INFO	<< "Attack:"	<< this->AttackDamage	<< "\n"
				<< PRINT_RESET	<< std::flush;
}

void	ClapTrap::displayInfo(void) const
{
	ClapTrap::displaySelf();
}

std::string const	ClapTrap::getType(void) const
{
	return (this->type);
}

void	ClapTrap::setType(const std::string new_type)
{
	this->type = new_type;
}

const std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHPMax(void) const
{
	return (this->HPMax);
}

void	ClapTrap::setHPMax(const unsigned int value)
{
	this->HPMax = value;
}

unsigned int	ClapTrap::getHPCurrent(void) const
{
	return (this->HPCurrent);
}

void	ClapTrap::setHPCurrent(const unsigned int value)
{
	if (value > this->HPMax)
		this->HPCurrent = HPMax;
	else
		this->HPCurrent = value;
}

unsigned int	ClapTrap::getEPMax(void) const
{
	return (this->EPMax);
}

void	ClapTrap::setEPMax(const unsigned int value)
{
	this->EPMax = value;
}

unsigned int	ClapTrap::getEPCurrent(void) const
{
	return (this->EPCurrent);
}

void	ClapTrap::setEPCurrent(const unsigned int value)
{
	if (value > this->EPMax)
		this->EPCurrent = EPMax;
	else
		this->EPCurrent = value;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->AttackDamage);
}

void	ClapTrap::setAttackDamage(const unsigned int value)
{
		this->AttackDamage = value;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
