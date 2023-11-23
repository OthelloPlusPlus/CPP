/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/10 14:32:34 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
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

PhoneBook::PhoneBook(void)
{
	std::cout	<< C_GREEN	<< "PhoneBook constructed"
				<< C_RESET	<< std::endl;
}

PhoneBook::PhoneBook(const PhoneBook &src)
{
	*this = src;
	std::cout	<< C_GREEN	<< "PhoneBook copy constructed"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

PhoneBook::~PhoneBook(void)
{
	std::cout	<< C_RED	<< "PhoneBook deconstructed"
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

bool	PhoneBook::commandAdd(void)
{
	std::string	data[5];

	data[0] = this->requestInfoString("First name: ");
	if (data[0].empty())
		return (false);
	data[1] = this->requestInfoString("Last name: ");
	if (data[1].empty())
		return (false);
	data[2] = this->requestInfoString("Nickname: ");
	if (data[2].empty())
		return (false);
	data[3] = this->requestInfoNumber("Phone number: ");
	if (data[3].empty())
		return (false);
	data[4] = this->requestInfoString("Darkest Secret: ");
	if (data[4].empty())
		return (false);
	this->contactAdd(data);
	std::cout	<<	C_GRAY	<< "Contact has been added"
				<< std::endl;
	return (true);
}

void	PhoneBook::commandFill(void)
{
	std::string	data[5];
	size_t	i;

	data[0] = "Lorem";
	data[1] = "ipsum";
	data[2] = "Infinite";
	data[3] = "+316-0123 4567 89";
	data[4] = "I don't actually mean anything!";

	i = 0;
	std::string	nickname;
	nickname = "Infinite";
	while (i < sizeof(this->contact) / sizeof(Contact))
	{
		if (this->contact[i].getFirstName().empty())
			this->contactAdd(data);
		data[2] = data[2] + '!';
		nickname = nickname + '!';
		i++;
	}
	std::cout	<< C_GRAY	<< "The Phonebook has been filled."
				<< C_RESET	<< std::endl;
}

bool	PhoneBook::commandDelete(void)
{
	size_t	index;
	size_t	i;

	index = PhoneBook::requestIndex();
	if (index == static_cast<size_t>(-1))
		return (false);
	i = 0;
	while (i < sizeof(this->contact) / sizeof(Contact) - 1)
	{
		if (i >= index)
		{
			this->contact[i] = this->contact[i + 1];
			this->contact[i + 1] = Contact();
		}
		i++;
	}
	return (true);
}

bool	PhoneBook::commandSearch(void)
{
	std::string	input;
	size_t		index;

	index = PhoneBook::requestIndex();
	if (index == static_cast<size_t>(-1))
		return (false);
	this->contact[index].printDetails();
	return (true);
}

void	PhoneBook::commandHelp(void) const
{
	std::cout	<< std::left
				<< std::setw(8)	<< "ADD"
				<< "save a new contact\n"
				<< std::setw(8)	<< "FILL"
				<< "fills empty contacts with information for testing\n"
				<< std::setw(8)	<< "SEARCH"
				<< "display a specific contact\n"
				<< std::setw(8)	<< "EXIT"
				<< "the program quits and the contacts are lost forever!"
				<< std::right
				<< std::endl;
}

void	PhoneBook::contactAdd(std::string data[5])
{
	static int		i = 0;

	for (unsigned long j = 0;
		j < sizeof(this->contact) / sizeof(Contact); ++j)
		if (this->contact[j].getFirstName().empty())
		{
			i = j;
			break ;
		}
	this->contact[i] = Contact(data);
	i = (i + 1) % 8;
}

size_t		PhoneBook::requestIndex(void)
{
	std::string	str;
	size_t		index;
	size_t		max;

	if (this->phonebookContainsContacts() == false)
		return (-1);
	max = displayContactSummary();
	while (1)
	{
		str = PhoneBook::requestInfoNumber("Contact Index> ");
		if (str.empty())
			return (-1);
		if (str.find_first_not_of("1234567890") != static_cast<size_t>(-1))
		{
			std::cout	<< C_GRAY	<< "Invalid input"
						<< C_RESET	<< std::endl;
			continue ;
		}
		index = std::stoi(str) - 1;
		if (index >= 0 && index < max)
			break ;
		std::cout	<< C_GRAY	<< "Number out of range"
					<< C_RESET	<< std::endl;
	}
	if (index < 0 || index > max)
		return (-1);
	return (index);
}

size_t	PhoneBook::displayContactSummary(void)
{
	size_t	i;

	if (this->phonebookContainsContacts() == false)
		return (-1);
	PhoneBook::displayContactSummaryHead();
	i = 0;
	while (i < sizeof(this->contact) / sizeof(Contact) && \
			!this->contact[i].getFirstName().empty())
	{
		this->contact[i].printSummary(i);
		i++;
	}
	std::cout	<< std::string(45, '=')
				<< std::endl;
	return (i);
}

bool	PhoneBook::phonebookContainsContacts(void)
{
	if (this->contact[0].getFirstName().empty())
	{
		std::cout	<< C_GRAY	<< "Phonebook is still empty...\n"
					<< "Use ADD to add contacts."
					<< C_RESET	<< std::endl;
		return (false);
	}
	return (true);
}

void	PhoneBook::displayContactSummaryHead(void) const
{
	std::cout	<< std::right
				<< std::string(45, '=')	<< "\n"
				<< "|"
				<< std::setw(11)	<< "Index|"
				<< std::setw(11)	<< "First Name|"
				<< std::setw(11)	<< "Last Name|"
				<< std::setw(11)	<< "Nickname|"
				<< "\n"
				<< std::string(45, '=')
				<< std::endl;
}

std::string	PhoneBook::requestInfoString(std::string prompt)
{
	std::string str;
	size_t		attempts;

	attempts = 0;
	while (str.empty())
	{
		if (attempts++ >= 8)
		{
			std::cout	<< C_GRAY	<< "Too many invalid attempts..."
						<< C_RESET	<< std::endl;
			break ;
		}
		std::cout	<< std::left	<< std::setw(16) << prompt
					<< std::flush;
		getline(std::cin, str);
		if (std::cin.eof())
			break ;
		if (str.empty())
			std::cout	<< C_GRAY	<< "Field is required"
						<< C_RESET	<< std::endl;
	}
	return (str);
}

std::string	PhoneBook::requestInfoNumber(std::string prompt)
{
	std::string num;
	size_t		attempts;

	attempts = 0;
	while (!std::cin.eof() && num.empty())
	{
		if (attempts++ >= 8)
		{
			std::cout	<< C_GRAY	<< "Too many invalid attempts..."
						<< C_RESET	<< std::endl;
			break ;
		}
		std::cout	<< std::left	<< std::setw(16) << prompt
				<< std::flush;
		getline(std::cin, num);
		if (std::cin.eof())
			break ;
		if (num.empty())
			std::cout	<< C_GRAY	<< "Field is required"
						<< C_RESET	<< std::endl;
		else if (num.find_first_not_of(" 1234567890-+") != static_cast<size_t>(-1))
		{
			std::cout	<< C_GRAY	<< "Invalid input. Numerical phonenumber only."
						<< C_RESET	<<std::endl;
			num.clear();
			continue ;
		}
	}
	return (num);
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

PhoneBook	&PhoneBook::operator=(const PhoneBook &src)
{
	unsigned long	i;

	i = 0;
	while (i < sizeof(this->contact) / sizeof(Contact))
	{
		this->contact[i].setFirstName(src.contact[i].getFirstName());
		this->contact[i].setLastName(src.contact[i].getLastName());
		this->contact[i].setNickname(src.contact[i].getNickname());
		this->contact[i].setPhoneNumber(src.contact[i].getPhoneNumber());
		this->contact[i].setDarkestSecret(src.contact[i].getDarkestSecret());
		i++;
	}
	return (*this);
}
