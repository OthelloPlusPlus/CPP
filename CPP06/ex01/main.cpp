/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <iostream>
// std::cout

static void	testSerializer(double val, const char *str);

int	main(void)
{
	print::headerLine("Exercise 01: Serialization");
	testSerializer(23.23, "Lorem ipsum");
	return (0);
}

static void	testSerializer(double val, const char *str)
{
	Data		file;
	uintptr_t	raw = Serializer::serialize(&file);
	Data		*ptr = Serializer::deserialize(raw);
	Data		*comp = &file;

	file.value = val;
	ptr->str = str;
	print::subHeaderLine("Address");
	std::cout	<< "file\t"	<< &file	<< '\n'
				<< "ptr\t"	<< ptr		<< '\n'
				<< "comp\t"	<< comp		<< '\n'
				<< "raw\t"	<< raw		<< '\n';
	print::subHeaderLine("Content");
	std::cout	<< "file\t"	<< file.value	<< '\t'	<< file.str	<< '\n'
				<< "ptr\t"	<< ptr->value	<< '\t'	<< ptr->str	<< '\n'
				<< std::flush;
}
