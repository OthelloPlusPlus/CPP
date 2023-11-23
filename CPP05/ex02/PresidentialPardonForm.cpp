/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "PresidentialPardonForm"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "PresidentialPardonForm"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout	<< C_DRED	<< "Deconstructor "
				<< C_RED	<< "PresidentialPardonForm"
				<< C_DRED	<< " called"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	PresidentialPardonForm::action(void) const
{
	std::cout	<< C_LORANGE	<< this->target
				<< C_RESET	<< " has been pardoned by "
				<< C_LORANGE	<< "Zaphod Beeblebrox"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return (*this);
	this->target = src.target;
	return (*this);
}
