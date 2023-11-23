/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include<algorithm>
// std::transform

t_knownForms	Intern::knownForms2[] =
{
	{"shrubberycreation",	[](std::string target) -> AForm *{return new ShrubberyCreationForm(target);}},
	{"robotomyrequest",		[](std::string target) -> AForm *{return new RobotomyRequestForm(target);}},
	{"presidentialpardon",	[](std::string target) -> AForm *{return new PresidentialPardonForm(target);}},
};

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Intern::Intern(void)
{
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "Intern"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

Intern::Intern(const Intern &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "Intern"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Intern::~Intern(void)
{
	std::cout	<< C_DRED	<< "Deconstructor "
				<< C_RED	<< "Intern"
				<< C_DRED	<< " called"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

AForm *Intern::makeForm(std::string name, std::string target) const
{
	AForm 		*form = nullptr;
	std::string	adjusted;

	try
	{
		adjusted = this->convertName(name);
		for (unsigned int i = 0; i < sizeof(this->knownForms2) / sizeof(*this->knownForms2); ++i)
			if (this->knownForms2[i].name == adjusted)
			{
				form = this->knownForms2[i].constructor(target);
				break ;
			}
	}
	catch(const std::exception& e)
	{
		std::cerr	<< C_RED	<< "Error: "
					<< C_RESET	<< e.what()
					<< std::endl;
	}
	if (form)
		std::cout	<< C_RESET	<< "Intern creates "
					<< C_CYAN	<< form->getName()
					<< C_RESET	<< std::endl;
	else
		std::cout	<< C_RESET	<< "Intern could not find form "
					<< C_RED	<< name
					<< C_RESET	<< std::endl;
	return (form);
}

std::string	Intern::convertName(std::string &name) const
{
	std::string adj(name);

	adj.erase(std::remove(adj.begin(), adj.end(), ' '), adj.end());
	if (adj.empty())
		throw(Intern::FormNameError(adj));
	std::transform(adj.begin(), adj.end(), adj.begin(), tolower);
	std::size_t	pos = adj.rfind("form");
	if (pos != std::string::npos && pos + 4 == adj.length())
		adj.erase(adj.rfind("form"), std::string::npos);
	if (adj.empty())
		throw(Intern::FormNameError(name));
	return (adj);
}

/** ************************************************************************ **\
 * 
 * 	Nested Class Functions
 * 
\* ************************************************************************** */

Intern::FormNameError::FormNameError(std::string msg)
{
	if (msg.empty())
		this->message = "Intern needs a form name";
	else
		this->message = '\'' + msg + "' is not a valid form name";
}

const char	*Intern::FormNameError::what() const throw()
{
	return (message.c_str());
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Intern	&Intern::operator=(const Intern &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
