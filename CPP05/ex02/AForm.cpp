/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
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

AForm::AForm(const std::string name, int signGrade, int execGrade): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (this->signGrade < 1)
		throw(AForm::GradeTooHighException(this->signGrade));
	if (this->execGrade < 1)
		throw(AForm::GradeTooHighException(this->execGrade));
	if (this->signGrade > 150)
		throw(AForm::GradeTooLowException(this->signGrade));
	if (this->execGrade > 150)
		throw(AForm::GradeTooLowException(this->execGrade));
	std::cout	<< C_DGREEN	<< "Default constructor "
				<< C_GREEN	<< "AForm"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

AForm::AForm(const AForm &src): name(src.name), signGrade(src.signGrade), execGrade(src.execGrade)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "AForm"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

AForm::~AForm(void)
{
	std::cout	<< C_DRED	<< "Deconstructor "
				<< C_RED	<< "AForm"
				<< C_DRED	<< " called"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	AForm::beSigned(Bureaucrat &bc)
{
	if (this->isSigned)
		throw (AForm::GeneralException("Form is already signed."));
	if (bc.getGrade() > this->signGrade)
		throw (AForm::GradeTooLowException(this->signGrade));
	this->isSigned = true;
}

void	AForm::execute(Bureaucrat &bc) const
{
	if (!this->isSigned)
		throw(AForm::GeneralException("Form needs to be signed before execution"));
	if (bc.getGrade() > this->execGrade)
		throw(AForm::GeneralException("Form requires rank " + std::to_string(this->execGrade) + " to be executed."));
	this->action();
}

void	AForm::printForm(void) const
{
	size_t	len = this->name.length();
	std::cout	<< std::left
				<< std::string(21 + len, '-') << '\n'
				<< std::setw(19)	<< "| AForm:"				<< std::setw(len)	<< this->name	<< " |\n"
				<< '|'	<< std::string(19 + len, ' ')	<< "|\n"
				<< std::setw(19)	<< "| Execution Grade: "	<< std::setw(len)	<< this->execGrade	<< " |\n"
				<< std::setw(19)	<< "| Sign Grade: "			<< std::setw(len)	<< this->signGrade	<< " |\n"
				<< std::setw(19)	<< "| Sign status: "		<< std::setw(len)	<< this->isSigned	<< " |\n"
				<< std::string(21 + len, '-') << std::endl;
}

const std::string	AForm::getName(void) const
{
	return (this->name);
}
	
bool	AForm::getIsSigned(void) const
{
	return (this->isSigned);
}
	
int	AForm::getSignGrade(void) const
{
	return (this->signGrade);
}
	
int	AForm::getExecGrade(void) const
{
	return (this->execGrade);
}
	
/** ************************************************************************ **\
 * 
 * 	Nested Class Functions
 * 
\* ************************************************************************** */

AForm::GradeTooHighException::GradeTooHighException(int grade)
{
	this->message = "Grade " + std::to_string(grade) + " error: No one could ever sign this...";
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(int grade)
{
	this->message = "Form requires at least rank " + std::to_string(grade) + '.';
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

AForm::GeneralException::GeneralException(std::string msg): message(msg)
{
}

const char	*AForm::GeneralException::what() const throw()
{
	return (message.c_str());
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

AForm	&AForm::operator=(const AForm &src)
{
	if (this == &src)
		return (*this);
	this->isSigned = src.isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const AForm &src)
{
	out	<< src.getName()	<< '(';
	if (src.getIsSigned())
		out	<< "signed, ";
	else
		out	<< "unsigned, ";
	out	<< src.getSignGrade()	<< '/'	<< src.getExecGrade()	<< ')';
	return (out);
}
