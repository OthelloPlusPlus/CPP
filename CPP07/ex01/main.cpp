/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:36:14 by ohengelm          #+#    #+#             */
/*   Updated: 2023/11/30 18:50:26 by ohengelm         ###   ########.fr       */
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

void	argvTests(int argc, char **argv);
// void	defaultTests(void);
int		testEvaluation(void);
// template <typename T>
// void	(*getRandomFunction())(T &);
// int		(*getRandomFunction())(int);

template <typename T>
void	toUpper(T &c);
template <typename T>
void	toLower(T &c);
template <typename T>
void	convertLeet(T &c);
template <typename T>
void	makeOdd(T &c);

// int		convert_leet(int c);
// int		make_odd(int i);

int	main(int argc, char **argv)
{
	print::headerLine("Exercise 01: Iter");
	std::srand(std::time(NULL));
	// if (argc > 1)
	// 	argvTests(argc, argv);
	// else
	// {
		// defaultTests();
		testEvaluation();
	// }
	return (0);
	(void)argv;
	(void)argc;
}

// void	argvTests(int argc, char **argv)
// {
// 	print::subHeaderLine("Testing with argv strings");
// 	for (int i = 1; i < argc; ++i)
// 		::testIter(argv[i], std::strlen(argv[i]), getRandomFunction<char>());
// }

// void	defaultTests(void)
// {
// 	print::subHeaderLine("Default test - char *");
// 	char	carr[] = "char\tHello World";
// 	::testIter(carr, std::strlen(carr), getRandomFunction<char>());

// 	print::subHeaderLine("Default test - std::string");
// 	std::string	sarr = "std::string\tHello World";
// 	::testIter(sarr, sarr.length(), getRandomFunction<std::string>());

// 	print::subHeaderLine("Default test - int *");
// 	int	iarr[] = {79, 116, 104, 101, 108, 108, 111, 50, 51};
// 	::testIter(iarr, sizeof(iarr) / sizeof(*iarr), getRandomFunction<int>());
	
// 	print::subHeaderLine("Default test - double *");
// 	double darr[] = {1.1, 2.3, 3.3, 6.7};
// 	::testIter(darr, sizeof(darr) / sizeof(*darr), getRandomFunction<double>());
// }

// template <typename T>
// void	(*getRandomFunction())(T &)
// {
// 	switch (rand() % 4)
// 	{
// 		case 0:
// 			std::cout	<< C_LORANGE	<< "Lowercase";
// 			return (&toUpper);
// 		case 1:
// 			std::cout	<< C_LORANGE	<< "Uppercase";
// 			return (&toLower);
// 		case 2:
// 			std::cout	<< C_LORANGE	<< "Make odd";
// 			return (&makeOdd);
// 		default:
// 			std::cout	<< C_LORANGE	<< "1337 Speak";
// 			return (&convertLeet);
// 	}
// }
// int		(*getRandomFunction())(int)
// {
// 	switch (rand() % 4)
// 	{
// 		case 0:
// 			std::cout	<< C_LORANGE	<< "Lowercase";
// 			return (std::tolower);
// 		case 1:
// 			std::cout	<< C_LORANGE	<< "Uppercase";
// 			return (std::toupper);
// 		case 2:
// 			std::cout	<< C_LORANGE	<< "Make odd";
// 			return (&make_odd);
// 		default:
// 			std::cout	<< C_LORANGE	<< "1337 Speak";
// 			return (&convert_leet);
// 	}
// }
template <typename T>
void	toUpper(T &c)
{
	c = std::toupper(static_cast<char>(c));
}

template <typename T>
void	toLower(T &c)
{
	c = std::tolower(static_cast<char>(c));
}

template <typename T>
void	convertLeet(T &c)
{
	int	value = std::toupper(static_cast<int>(c));
	// c = std::toupper(c);
	switch (value)
	{
		case 'O': c = '0'; break;
		case 'I':
		case 'L': c = '1'; break;
		case 'Z': c = '2'; break;
		case 'E': c = '3'; break;
		case 'A': c = '4'; break;
		case 'S': c = '5'; break;
		case 'G': c = '6'; break;
		case 'T': c = '7'; break;
		case 'B': c = '8'; break;
		case 'J': c = '9'; break;
		default:	break;
	}
	c = static_cast<T>(c);
}

template <typename T>
void	makeOdd(T &c)
{
	c = static_cast<int>(c);
	// if (c % 2 == 0)
	// 	++c;
	// c = (c + 1 - (c % 2));
}

// int	convert_leet(int c)
// {
// 	c = ::toupper(c);
// 	switch (c)
// 	{
// 		case 'O':	return ('0');
// 		case 'I':
// 		case 'L':	return ('1');
// 		case 'Z':	return ('2');
// 		case 'E':	return ('3');
// 		case 'A':	return ('4');
// 		case 'S':	return ('5');
// 		case 'G':	return ('6');
// 		case 'T':	return ('7');
// 		case 'B':	return ('8');
// 		case 'J':	return ('9');
// 		default:	break;
// 	}
// 	return (c);
// }

// int	make_odd(int i)
// {
// 	return (i + 1 - (i % 2));
// }

class Awesome
	{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream	&operator<<( std::ostream & o, Awesome const & rhs )
	{
	o << rhs.get();
	return o;
}

template< typename T >
void printArray( T& x )
{
	std::cout << x << std::endl;
	return;
}
int	testEvaluation(void)
{
	print::subHeaderLine("Evaluation Tests");
	// int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	// iter( tab, 5, printArray<const int> );
	iter( tab2, 5, printArray<Awesome> );

	return 0;
}
