/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <cstdlib>
// std::srand
#include <ctime>
// std::time

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

bool	RobotomyRequestForm::seed = false;

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
	if (!this->seed)
	{
		std::srand(std::time(nullptr));
		this->seed = true;
	}
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "RobotomyRequestForm"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "RobotomyRequestForm"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout	<< C_DRED	<< "Deconstructor "
				<< C_RED	<< "RobotomyRequestForm"
				<< C_DRED	<< " called"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	RobotomyRequestForm::action(void) const
{
	std::cout	<< C_DGRAY	<< "*SOME DRILLING NOISES*\n";
	if (std::rand() % 2)
		std::cout	<< C_LORANGE	<< this->target
					<< C_RESET<< " has been robotomized."	<< std::endl;
	else
		std::cout	<< C_LORANGE	<< this->target
					<< C_RESET	<< "'s robotomy has failed."	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return (*this);
	this->target = src.target;
	return (*this);
}
