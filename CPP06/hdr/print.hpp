/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 20:21:11 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/06/16 18:39:51 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HPP
# define PRINT_HPP

#include "colors.hpp"

# include <iostream>
// std::
# include <iomanip>
// std::setw()

namespace print
{
	template <typename T>
	typename std::enable_if<std::is_same<T, char *>::value || 
							std::is_same<T, const char *>::value ||
							std::is_same<T, std::string>::value>::type
	headerLine(T str)
	{
		std::cout	<< CB_ORANGE << C_BOLD << C_SILVER
					<< std::setw(80) << std::left << std::string(" ") + str
					<< C_RESET	<< std::endl;
	}

	template <typename T>
	typename std::enable_if<std::is_same<T, char *>::value || 
							std::is_same<T, const char *>::value ||
							std::is_same<T, std::string>::value>::type
	subHeaderLine(T str)
	{
		std::cout	<< CB_DORANGE << C_BOLD << C_SILVER
					<< std::setw(42) << std::left << std::string(" ") + str
					<< C_RESET	<< std::endl;
	}
};

#endif
