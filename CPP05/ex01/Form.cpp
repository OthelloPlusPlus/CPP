/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
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

Form::Form(const std::string name, int signGrade, int execGrade): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (this->signGrade < 1)
		throw(Form::GradeTooHighException(this->signGrade));
	if (this->execGrade < 1)
		throw(Form::GradeTooHighException(this->execGrade));
	if (this->signGrade > 150)
		throw(Form::GradeTooLowException(this->signGrade));
	if (this->execGrade > 150)
		throw(Form::GradeTooLowException(this->execGrade));
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "Form"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

Form::Form(const Form &src): name(src.name), signGrade(src.signGrade), execGrade(src.execGrade)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "Form"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Form::~Form(void)
{
	std::cout	<< C_DRED	<< "Deconstructor "
				<< C_RED	<< "Form"
				<< C_DRED	<< " called"
				<< C_RESET	<< std::endl;
	(void)execGrade;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Form::beSigned(Bureaucrat &bc)
{
	if (this->isSigned)
		throw (std::runtime_error("already signed"));
	if (bc.getGrade() > this->signGrade)
		throw (Form::GradeTooLowException(this->signGrade));
	this->isSigned = true;
}

void	Form::printForm(void) const
{
	size_t	len = this->name.length();
	std::cout	<< std::left
				<< std::string(21 + len, '-') << '\n'
				<< std::setw(19)	<< "| Form:"				<< std::setw(len)	<< this->name	<< " |\n"
				<< '|'	<< std::string(19 + len, ' ')	<< "|\n"
				<< std::setw(19)	<< "| Execution Grade: "	<< std::setw(len)	<< this->execGrade	<< " |\n"
				<< std::setw(19)	<< "| Sign Grade: "			<< std::setw(len)	<< this->signGrade	<< " |\n"
				<< std::setw(19)	<< "| Sign status: "		<< std::setw(len)	<< this->isSigned	<< " |\n"
				<< std::string(21 + len, '-') << std::endl;
}

const std::string	Form::getName(void) const
{
	return (this->name);
}
	
bool	Form::getIsSigned(void) const
{
	return (this->isSigned);
}
	
int	Form::getSignGrade(void) const
{
	return (this->signGrade);
}
	
int	Form::getExecGrade(void) const
{
	return (this->execGrade);
}
	
/** ************************************************************************ **\
 * 
 * 	Nested Class Functions
 * 
\* ************************************************************************** */

Form::GradeTooHighException::GradeTooHighException(int grade)
{
	this->message = "Grade " + std::to_string(grade) + " error: No one could ever sign this...";
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

Form::GradeTooLowException::GradeTooLowException(int grade)
{
	this->message = "Form requires rank " + std::to_string(grade) + " to be signed.";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Form	&Form::operator=(const Form &src)
{
	if (this == &src)
		return (*this);
	this->isSigned = src.isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Form &src)
{
	out	<< src.getName()	<< '(';
	if (src.getIsSigned())
		out	<< "signed, ";
	else
		out	<< "unsigned, ";
	out	<< src.getSignGrade()	<< '/'	<< src.getExecGrade()	<< ')';
	return (out);
}
