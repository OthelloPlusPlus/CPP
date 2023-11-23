/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 20:21:46 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/23 20:58:41 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "print.hpp"
#include "colors.hpp"

# include <iostream>
// std::
# include <iomanip>
// std::setw()

void	print::headerLine(std::string string)
{
	string.insert(0, " ");
	std::cout	<< "\n"
				<< CB_ORANGE << C_BOLD << C_SILVER
				<< std::setw(80) << std::left << string
				<< C_RESET	<< std::endl;
}

void	print::subHeaderLine(std::string string)
{
	string.insert(0, " ");
	std::cout	<< "\n"
				<< CB_DORANGE << C_BOLD << C_SILVER
				<< std::setw(42) << std::left << string
				<< C_RESET	<< std::endl;
}