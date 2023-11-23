/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

MateriaSource::MateriaSource(void)
{
	int	i;

	this->size = sizeof(known) / sizeof(AMateria *);
	i = 0;
	while (i < this->size)
		known[i++] = NULL;
	// std::cout	<< C_DGREEN	<< "Ollivander made a "
	// 			<< C_GREEN	<< "MateriaSource"
	// 			<< C_DGREEN	<< "."
	// 			<< C_RESET	<< "\tThe wand chooses the wizard, remember..."	<< std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
	// std::cout	<< C_DGREEN	<< "Copy constructor "
	// 			<< C_GREEN	<< "MateriaSource"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

MateriaSource::~MateriaSource(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < this->size)
	{
		if (this->known[i])
		{
			j = 0;
			while (j < i && this->known[j] != this->known[i])
				j++;
			if (j == i)
				delete this->known[i];
		}
		i++;
	}
	// std::cout	<< C_RED	<< "MateriaSource"
	// 			<< C_DRED	<< " broke..."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void		MateriaSource::learnMateria(AMateria *type)
{
	int	i;

	i = 0;
	while (i < this->size && this->known[i] != 0)
		i++;
	if (i < this->size)
	{
		this->known[i] = type;
		// if (type)
		// 	std::cout	<< C_RESET	<< "Materia "
		// 				<< C_ORANGE	<< type->getType()		
		// 				<< C_RESET	<< " is added on slot "	
		// 				<< C_ORANGE	<< i	
		// 				<< C_RESET	<< std::endl;
	}
	else
		std::cout	<< C_PURPLE	<< "Source is full"
					<< C_RESET	<< std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int			i;

	i = 0;
	while (i < this->size)
	{
		if (this->known[i] && !this->known[i]->getType().compare(type))
			return (this->known[i]->clone());
		i++;
	}
	return (NULL);
}

void		MateriaSource::displayMateria(std::string const &head) const
{
	int	i;

	std::cout	<< CB_ORANGE	<< "  "	<< this	<< "  "	<< head	<< "  "
				<< C_RESET	<< "\n";
	i = 0;
	while (i < this->size)
	{
		std::cout	<< i	<< "\t"	<< this->known[i];
		if (this->known[i])
			std::cout	<< "\t"	<< this->known[i]->getType();
		std::cout	<< "\n";
		i++;
	}
	std::cout	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	int	i;

	if (this == &src)
		return (*this);
	i = 0;
	while (i < src.size)
	{
		if (src.known[i])
			this->known[i] = src.known[i]->clone();
		else
			this->known[i] = 0;
		i++;
	}
	this->size = src.size;
	return (*this);
}
