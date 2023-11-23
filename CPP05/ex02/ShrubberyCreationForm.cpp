/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <fstream>
// std::ofstream

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "ShrubberyCreationForm"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "ShrubberyCreationForm"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout	<< C_DRED	<< "Deconstructor "
				<< C_RED	<< "ShrubberyCreationForm"
				<< C_DRED	<< " called"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	ShrubberyCreationForm::action(void) const
{
	std::ofstream	out(this->target + "_shrubbery");
	if (!out)
		throw(std::runtime_error("Couldn't open " + this->target + "_shrubbery"));
	out	<< "                      ,@@@@@@@,\n"
		<< "              ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		<< "           ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		<< "          ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		<< "          %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		<< "          %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		<< "  ______  `&%\\ ` /%&'    |.|        \\ '|8'\n"
		<< " /|_||_\\`.__  |o|        | |         | |\n"
		<< "(   _    _ _\\ |.|        | |         | |\n"
		<< "=`-(_)--(_)-'/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_"
		<< std::flush;
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);
	this->target = src.target;
	return (*this);
}
