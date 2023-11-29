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
#include <string>
// std::string

namespace print
{
	template <typename T>
# if __cplusplus >= 201103L
	typename std::enable_if<std::is_same<T, char *>::value || 
							std::is_same<T, const char *>::value ||
							std::is_same<T, std::string>::value>::type
	headerLine(T str)
# else
	void headerLine(T str)
# endif
	{
		std::cout	<< CB_ORANGE << C_BOLD << C_SILVER
					<< std::setw(80) << std::left << std::string(" ") + str
					<< C_RESET	<< std::endl;
	}

	template <typename T>
# if __cplusplus >= 201103L
	typename std::enable_if<std::is_same<T, char *>::value || 
							std::is_same<T, const char *>::value ||
							std::is_same<T, std::string>::value>::type
	subHeaderLine(T str)
# else
	void subHeaderLine(T str)
# endif
	{
		std::cout	<< CB_DORANGE << C_BOLD << C_SILVER
					<< std::setw(42) << std::left << std::string(" ") + str
					<< C_RESET	<< std::endl;
	}

	template <typename T>
# if __cplusplus >= 201103L
	typename std::enable_if<std::is_same<T, char *>::value || 
							std::is_same<T, const char *>::value ||
							std::is_same<T, std::string>::value>::type
	note(T str)
# else
	void note(T str)
# endif
	{
		std::cout	<< CB_GRAY << C_BOLD << C_ORANGE
					<< std::setw(42) << std::left << std::string(" Note: ") + str
					<< C_RESET	<< std::endl;
	}
	template <typename T>
# if __cplusplus >= 201103L
	typename std::enable_if<std::is_same<T, char *>::value || 
							std::is_same<T, const char *>::value ||
							std::is_same<T, std::string>::value>::type
	tableHead(T str)
# else
	void tableHead(T str)
# endif
	{
		std::string string(str);
		int			tabSize = 8;
		std::string	temp(tabSize, ' ');
		const char	*spaces = temp.c_str();

		for (size_t i = 0; i < string.length(); ++i)
		{
			if (string[i] == '\t')
			{
				string.erase(i, 1);
				string.insert(i, spaces, tabSize - (i % tabSize));
				--i;
			}
		}
		std::cout	<< CB_SILVER << C_BOLD << C_ORANGE
					<< std::setw(42) << std::left << string
					<< C_RESET	<< std::endl;
	}
};

#endif
