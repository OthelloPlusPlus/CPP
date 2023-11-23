/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 16:03:07 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 19:15:16 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"

#include <iostream>
// std::
#include <iomanip>
// std::setw()

#define NAME	13
#define ADDRESS	17
#define VALUE	23

static void	st_print_info_line(std::string string);

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	st_print_info_line("Default Info");
	std::cout	<< CB_DORANGE << C_BOLD << C_SILVER\
				<< std::left;
	std::cout	<< std::setw(NAME)	<< " NAME"
				<< std::setw(ADDRESS)	<< " MEMORY ADDRESS"
				<< std::setw(VALUE)	<< " VALUE"
				<< C_RESET	<< "\n";
	std::cout	<< std::setw(NAME)	<< "string"
				<< std::setw(ADDRESS)	<< &string
				<< std::setw(VALUE)	<< string
				<< "\n";
	std::cout	<< std::setw(NAME)	<< "*stringPTR"
				<< std::setw(ADDRESS)	<< &stringPTR
				<< std::setw(VALUE)	<< *stringPTR
				<< "\n";
	std::cout	<< std::setw(NAME)	<< "&stringREF"
				<< std::setw(ADDRESS)	<< &stringREF
				<< std::setw(VALUE)	<< stringREF
				<< "\n";
	std::cout	<< std::flush;

	stringREF = "THE BRAIN IS GONE";
	st_print_info_line("Changed stringREF");
	std::cout	<< CB_DORANGE << C_BOLD << C_SILVER\
				<< std::left;
	std::cout	<< std::setw(NAME)	<< " NAME"
				<< std::setw(ADDRESS)	<< " MEMORY ADDRESS"
				<< std::setw(VALUE)	<< " VALUE"
				<< C_RESET	<< "\n";
	std::cout	<< std::setw(NAME)	<< "string"
				<< std::setw(ADDRESS)	<< &string
				<< std::setw(VALUE)	<< string
				<< "\n";
	std::cout	<< std::setw(NAME)	<< "*stringPTR"
				<< std::setw(ADDRESS)	<< &stringPTR
				<< std::setw(VALUE)	<< *stringPTR
				<< "\n";
	std::cout	<< std::setw(NAME)	<< "&stringREF"
				<< std::setw(ADDRESS)	<< &stringREF
				<< std::setw(VALUE)	<< stringREF
				<< "\n";
	std::cout	<< std::flush;
	
	return (0);
}

static void	st_print_info_line(std::string string)
{
	string.insert(0, " ");
	std::cout	<< "\n"
				<< CB_ORANGE << C_BOLD << C_SILVER\
				<< std::setw(80) << std::left << string\
				<< C_RESET\
				<< std::endl;
}
