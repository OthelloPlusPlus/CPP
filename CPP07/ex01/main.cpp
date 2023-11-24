/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:36:14 by ohengelm          #+#    #+#             */
/*   Updated: 2023/11/24 20:36:15 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "colors.hpp"
#include "print.hpp"

#include <iostream>
// std::cout
#include <cstring>
// std::strlen
#include <cstdlib>
// std::rand
#include <ctime>
// std::time

void	defaultTests(void);
void	argvTests(int argc, char **argv);
int		(*getRandomFunction())(int);

int		convert_leet(int c);
int		make_odd(int i);

int	main(int argc, char **argv)
{
	print::headerLine("Exercise 01: Iter");
	std::srand(std::time(NULL));
	if (argc > 1)
		argvTests(argc, argv);
	else
		defaultTests();
	return (0);
}

void	defaultTests(void)
{
	print::subHeaderLine("Default test - char *");
	char	carr[] = "char\tHello World";
	::testIter(carr, std::strlen(carr), getRandomFunction());

	print::subHeaderLine("Default test - std::string");
	std::string	sarr = "std::string\tHello World";
	::testIter(sarr, sarr.length(), getRandomFunction());

	print::subHeaderLine("Default test - int *");
	int	iarr[] = {79, 116, 104, 101, 108, 108, 111, 50, 51};
	::testIter(iarr, sizeof(iarr) / sizeof(*iarr), getRandomFunction());
	
	print::subHeaderLine("Default test - double *");
	double darr[] = {1.1, 2.3, 3.3, 6.7};
	::testIter(darr, sizeof(darr) / sizeof(*darr), getRandomFunction());
}

void	argvTests(int argc, char **argv)
{
	print::subHeaderLine("Testing with argv strings");
	for (int i = 1; i < argc; ++i)
		::testIter(argv[i], std::strlen(argv[i]), getRandomFunction());
}

int		(*getRandomFunction())(int)
{
	switch (rand() % 4)
	{
		case 0:
			std::cout	<< C_LORANGE	<< "Lowercase";
			return (std::tolower);
		case 1:
			std::cout	<< C_LORANGE	<< "Uppercase";
			return (std::toupper);
		case 2:
			std::cout	<< C_LORANGE	<< "Make odd";
			return (&make_odd);
		default:
			std::cout	<< C_LORANGE	<< "1337 Speak";
			return (&convert_leet);
	}
}

int	convert_leet(int c)
{
	c = ::toupper(c);
	switch (c)
	{
		case 'O':	return ('0');
		case 'I':
		case 'L':	return ('1');
		case 'Z':	return ('2');
		case 'E':	return ('3');
		case 'A':	return ('4');
		case 'S':	return ('5');
		case 'G':	return ('6');
		case 'T':	return ('7');
		case 'B':	return ('8');
		case 'J':	return ('9');
		default:	break;
	}
	return (c);
}

int	make_odd(int i)
{
	return (i + 1 - (i % 2));
}
