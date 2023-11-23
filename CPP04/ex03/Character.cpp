/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Character::Character(std::string name): name(name)
{
	int	i;

	this->inv_max = (int)sizeof(inventory) / sizeof(AMateria *);
	i = 0;
	while (i < this->inv_max)
		this->inventory[i++] = 0;
	// std::cout	<< C_GREEN	<< this->name
	// 			<< C_DGREEN	<< " apparated."
	// 			<< C_RESET	<< std::endl;
}

Character::Character(const Character &src)
{
	*this = src;
	// std::cout	<< C_DGREEN	<< "Copy constructor "
	// 			<< C_GREEN	<< "Character"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Character::~Character(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < this->inv_max)
	{
		if (this->inventory[i])
		{
			j = 0;
			while (j < i && this->inventory[j] != this->inventory[i])
				j++;
			if (j == i)
				delete this->inventory[i];
		}
		i++;
	}
	// std::cout	<< C_RED	<< this->name
	// 			<< C_DRED	<< " disapparated."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */


std::string const	&Character::getName(void) const
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	int	i;

	if (!m)
	{
		std::cout	<< C_PURPLE	<< "Materia does not exist."
					<< C_RESET	<<	std::endl;
		return ;
	}
	i = 0;
	while (i < this->inv_max && this->inventory[i] != 0)
		i++;
	if (i >= inv_max)
		std::cout	<< C_ORANGE	<< this->name	<< "'s"
					<< C_RESET	<< " inventory is full."
					<< std::endl;
	else
	{
		this->inventory[i] = m;
		// std::cout	<< C_ORANGE	<< this->name
		// 			<< C_RESET	<< " equipped "
		// 			<< C_ORANGE	<< m->getType()
		// 			<< C_RESET	<< " in inventory slot "
		// 			<< C_ORANGE	<< i
		// 			<< C_RESET	<< "."	<< std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (this->checkSlot(idx))
	{
		std::cout	<< C_ORANGE	<< this->name
					<< C_RESET	<< " unequipped "
					<< C_ORANGE	<< this->inventory[idx]->getType()
					<< C_RESET	<< "."	<< std::endl;
		this->inventory[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (this->checkSlot(idx))
		this->inventory[idx]->cast(this->getName(), target.getName());
}

void	Character::displayCharacter(void)
{
	int	i;

	std::cout	<< CB_ORANGE	<< "  "	<< this	<< "  "	<< this->name	<< "  "
				<< C_RESET	<< "\n";
	i = 0;
	while (i < this->inv_max)
	{
		std::cout	<< i	<< "\t"	<< this->inventory[i];
		if (this->inventory[i])
			std::cout	<< "\t"	<< this->inventory[i]->getType();
		std::cout	<< "\n";
		i++;
	}
}

bool	Character::checkSlot(int idx)
{
	if (idx < 0 || idx >= this->inv_max)
	{
		std::cout	<< C_PURPLE	<<	"Invalid inventory slot."
					<< C_RESET	<<	std::endl;
		return (false);
	}
	if (!this->inventory[idx])
	{
		std::cout	<< C_ORANGE	<< this->name
					<< C_RESET	<< " has nothing equiped in slot " 
					<< C_ORANGE	<< idx
					<< C_RESET	<< "."	<< std::endl;
		return (false);
	}
	return (true);
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Character	&Character::operator=(const Character &src)
{
	int	i;

	if (this == &src)
		return (*this);
	i = 0;
	while (i < src.inv_max)
	{
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = 0;
		i++;
	}
	this->inv_max = src.inv_max;
	this->name = src.name;
	return (*this);
}
