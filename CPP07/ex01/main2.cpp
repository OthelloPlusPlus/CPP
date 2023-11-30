/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:50 by ohengelm          #+#    #+#             */
/*   Updated: 2023/11/30 20:54:25 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "testTemplates.hpp"
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
void	defaultTests(void);

template <typename T, typename PTR, typename INDEX>
void	runTest(PTR *ptr, INDEX len);
template <typename T,typename PTR, typename INDEX, typename FUNC>
void	runTest(PTR *ptr, INDEX len, FUNC f);

class Awesome
{
	public:
		Awesome( void ) : _n( 22 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream	&operator<<( std::ostream & o, Awesome const & rhs )
	{ o << rhs.get(); return o; }

/** ************************************************************************ **\
 * 
 * 	Main
 * 
\* ************************************************************************** */

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

/** ************************************************************************ **\
 * 
 * 	Test functions
 * 
\* ************************************************************************** */

void	argvTests(int argc, char **argv)
{
	print::subHeaderLine("Testing with argv strings");
	for (int i = 1; i < argc; ++i)
		runTest<char>(argv[i], std::strlen(argv[i]), getRandomFunction<char>());
}

void	defaultTests(void)
{
	print::subHeaderLine("Default test - char *");
	int	iarr[] = {79, 116, 104, 101, 108, 108, 111, 50, 51};
	std::cout	<< C_LORANGE	<<	"toUpper";
	runTest<int>(iarr, sizeof(iarr) / sizeof(*iarr), toUpper<int>);

	print::subHeaderLine("Default test - int *");
	char	carr[] = "char\tHello World";
	std::cout	<< C_LORANGE	<<	"toLeet";
	runTest<char>(carr, std::strlen(carr), toLeet<char>);

	print::subHeaderLine("Default test - double *");
	double darr[] = {1.1, 2.3, 3.3, 6.7};
	std::cout	<< C_LORANGE	<<	"toOdd";
	runTest<double>(darr, sizeof(darr) / sizeof(*darr), toOdd<double>);

	print::subHeaderLine("Default test - class *");
	print::note("For more tests, add overloads");
	Awesome	clarr[5];
	::iter(clarr, 5, printArray<Awesome>);
	std::cout	<< std::endl;

	print::subHeaderLine("Error tests - NULL's");
	char *error = NULL;
	void (*ferror)(char &) = NULL;
	iter(error, 23, printArray<char>);
	iter(carr, std::strlen(carr), ferror);
}

/** ************************************************************************ **\
 * 
 * 	Templates
 * 
\* ************************************************************************** */

template <typename T, typename PTR, typename INDEX>
void	runTest(PTR *ptr, INDEX len)
{
	runTest<T>(ptr, len, getRandomFunction<T>());
}

template <typename T, typename PTR, typename INDEX, typename FUNC>
void	runTest(PTR *ptr, INDEX len, FUNC f)
{
	std::cout	<< C_RESET	<< "\n[";
	::iter(ptr, len, printArray<T>);
	std::cout	<<	']'	<< std::endl;
	::iter(ptr, len, f);
	std::cout	<< '[';
	::iter(ptr, len, printArray<T>);
	std::cout	<< ']'	<< std::endl;
}
