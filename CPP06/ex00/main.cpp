/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
// std::string

#include "ScalarConverter.hpp"
#include "print.hpp"

int	main(int argc, char **argv)
{
	print::headerLine("Exercise 00: Conversion of scalar types");
	for (int i = 1; i < argc; ++i)
	{
		print::subHeaderLine("Testing [" + std::string(argv[i]) + ']');
		ScalarConverter::convert(std::string(argv[i]));
	}
	return (0);
}
