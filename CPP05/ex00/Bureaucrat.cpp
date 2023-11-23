/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	this->grade = grade;
	this->validateVariables();
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "Bureaucrat"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "Bureaucrat"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Bureaucrat::~Bureaucrat(void)
{
	std::cout	<< C_DRED	<< "Deconstructor "
				<< C_RED	<< "Bureaucrat"
				<< C_DRED	<< " called"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Bureaucrat::validateVariables(void) const
{
	if (this->grade < 1)
		throw (Bureaucrat::GradeTooHighException(this->grade));
	if (this->grade > 150)
		throw (Bureaucrat::GradeTooLowException(this->grade));
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout	<< C_LORANGE	<< this->name
					<< C_RESET	<< " signed "
					<< C_CYAN	<< form.getName()
					<< C_RESET	<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout	<< C_LORANGE	<< this->name
					<< C_RESET	<< " coudn't sign "
					<< C_CYAN	<< form.getName()
					<< C_RESET	<< " because: "
					<< C_RESET	<< e.what()	<< std::endl;
	}
}

void	Bureaucrat::promote(void)
{
	++(*this);
}

void	Bureaucrat::demote(void)
{
	--(*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

/** ************************************************************************ **\
 * 
 * 	Nested Class Functions
 * 
\* ************************************************************************** */

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade)
{
	this->message = "Grade " + std::to_string(grade) + " error: We congratulate you on your promotion. However, there is no one with a grade high enough to sign your form.";
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int grade)
{
	this->message = "Grade " + std::to_string(grade) + " error: No one is this stupid...";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return (*this);
	this->grade = src.grade;
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)	//Bureaucrat++
{
	Bureaucrat	copy(*this);
	--this->grade;
	this->validateVariables();
	return (copy);
}

Bureaucrat	&Bureaucrat::operator++(void)	//++Bureaucrat
{
	--this->grade;
	this->validateVariables();
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)	//Bureaucrat--
{
	Bureaucrat	copy(*this);
	++this->grade;
	this->validateVariables();
	return (copy);
}

Bureaucrat	&Bureaucrat::operator--(void)	//--Bureaucrat
{
	++this->grade;
	this->validateVariables();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
	out	<< src.getName()	<< ", bureaucrat grade "	<< src.getGrade();
	return (out);
}
