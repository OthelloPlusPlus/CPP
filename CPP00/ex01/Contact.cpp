/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <iomanip>
//setw()

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Contact::Contact(void)
{
	// std::cout	<< C_GREEN	<< "Empty Contact constructed"
	// 			<< C_RESET	<< std::endl;
}

Contact::Contact(std::string data[5])
{
	// std::cout	<< C_GREEN	<< "Filled Contact constructed"
	// 			<< C_RESET	<< std::endl;
	this->first_name = data[0];
	this->last_name = data[1];
	this->nickname = data[2];
	this->phone_number = data[3];
	this->darkest_secret = data[4];
}

Contact::Contact(const Contact &src)
{
	*this = src;
	// std::cout	<< C_GREEN	<< "Contact copy constructed"
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Contact::~Contact(void)
{
	// std::cout	<< C_RED	<< "Contact deconstructed"
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

void	Contact::printSummary(int index)
{
	if (this->first_name.empty())
		return ;
	std::cout	<< "|";
	this->printSummarySegment(std::to_string(index + 1));
	this->printSummarySegment(this->first_name);
	this->printSummarySegment(this->last_name);
	this->printSummarySegment(this->nickname);
	std::cout	<< std::endl;
}

void	Contact::printSummarySegment(std::string segment)
{
	if (segment.length() <= 10)
		std::cout	<< std::setw(10)	<< segment;
	else
		std::cout	<< segment.substr(0, 9)
					<< ".";
	std::cout	<< "|";
}

void	Contact::printDetails(void)
{
	std::cout	<< std::left
				<< std::setw(16)	<< "First Name: "
				<< this->first_name	<< "\n"
				<< std::setw(16)	<< "Last Name: "
				<< this->last_name	<< "\n"
				<< std::setw(16)	<< "Nickname: "
				<< this->nickname	<< "\n"
				<< std::setw(16)	<< "Phone number: "
				<< this->phone_number	<< "\n"
				<< std::setw(16)	<< "Darkest secret: "
				<< this->darkest_secret
				<< std::right
				<< std::endl;
				
}

void	Contact::setFirstName(std::string first_name)
{
	this->first_name = first_name;
}

std::string	Contact::getFirstName(void) const
{
	return (this->first_name);
}

void	Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
}

std::string	Contact::getLastName(void) const
{
	return (this->last_name);
}

void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string	Contact::getNickname(void) const
{
	return (this->nickname);
}

void	Contact::setPhoneNumber(std::string phonenumber)
{
	this->phone_number = phonenumber;
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}

void	Contact::setDarkestSecret(std::string secret)
{
	this->darkest_secret = secret;
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Contact	&Contact::operator=(const Contact &src)
{
	this->first_name = src.first_name;
	this->last_name = src.last_name;
	this->nickname = src.nickname;
	this->phone_number = src.phone_number;
	this->darkest_secret = src.darkest_secret;
	return (*this);
}
