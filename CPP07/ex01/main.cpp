/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:50 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/01 17:46:07 by ohengelm         ###   ########.fr       */
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
#include <algorithm>
// std::reverse

void	argvTests(int argc, char **argv);
void	defaultTests(void);

template <typename T, typename PTR, typename INDEX>
void	runTest(PTR *ptr, INDEX len);
template <typename T,typename PTR, typename INDEX, typename FUNC>
void	runTest(PTR *ptr, INDEX len, FUNC f);
template <typename T, typename PTR, typename INDEX>
void	runTest(PTR *dst, PTR *src, INDEX len);
template <typename T,typename PTR, typename INDEX, typename FUNC>
void	runTest(PTR *dst, PTR *src, INDEX len, FUNC f);

class Awesome
{
	public:
		Awesome( void ) : _n( 23 ) { return; }
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
		runTest<char>(argv[i], std::strlen(argv[i]), getRandomVoidFunction<char>());
}

void	defaultTests(void)
{
	print::subHeaderLine("Default test - char *");
	int	iarr[] = {79, 116, 104, 101, 108, 108, 111, 50, 51};
	std::cout	<< C_LORANGE	<<	"toUpper";
	runTest<int>(iarr, sizeof(iarr) / sizeof(*iarr), toUpper<int>);
	runTest<int>(iarr, iarr, sizeof(iarr) / sizeof(*iarr), getRandomTFunction<int>());

	print::subHeaderLine("Default test - int *");
	char	carr[] = "char\tHello World";
	std::cout	<< C_LORANGE	<<	"toLeet";
	runTest<char>(carr, std::strlen(carr), toLeet<char>);
	runTest<char>(carr, carr, sizeof(carr) / sizeof(*carr), getRandomTFunction<int>());

	print::subHeaderLine("Default test - double *");
	double darr[] = {1.1, 2.3, 3.3, 6.7};
	std::cout	<< C_LORANGE	<<	"toOdd";
	runTest<double>(darr, sizeof(darr) / sizeof(*darr), toOdd<double>);
	runTest<double>(darr, darr, sizeof(darr) / sizeof(*darr), getRandomTFunction<int>());

	print::subHeaderLine("Default test - std::string");
	std::string string = "Lorem ipsum dolor sit amet";
	std::cout	<< C_LORANGE	<<	"toOdd";
	runTest<char>(&string[0], string.size(), toOdd<char>);

	print::subHeaderLine("Default test - std::string *");
#if __cplusplus >= 201103L
	std::string	ssarr[5] = {"Lorem", "ipsum", "dolor", "sit", "amet"};
	std::cout	<< C_LORANGE	<< "std::rotate";
	runTest<std::string>(ssarr, sizeof(ssarr) / sizeof(*ssarr), [](std::string &str){std::rotate(str.begin(), str.begin() + 1, str.end());});
	std::cout	<< C_LORANGE	<< "std::reverse";
	runTest<std::string>(ssarr, sizeof(ssarr) / sizeof(*ssarr), [](std::string &str){std::reverse(str.begin(), str.end());});
	::iter(ssarr, sizeof(ssarr) / sizeof(*ssarr), [](std::string &str){std::cout << str << ' ';});
	std::cout	<< std::endl;
#else
	print::note("Tests require c++11 or later");
#endif

	print::subHeaderLine("Default test - class *");
	Awesome	clarr[5];
	::iter(clarr, 5, printArray<Awesome>);
	std::cout	<< std::endl;
	print::note("For more tests, add overloads");

	print::subHeaderLine("Error tests");
#if __cplusplus >= 201103L
	iter<int>({}, 0, printArray<int>);
#endif
	iter(reinterpret_cast<char *>(NULL), 23, printArray<char>);
	iter(carr, std::strlen(carr), reinterpret_cast<void (*)(char&)>(NULL));
}

/** ************************************************************************ **\
 * 
 * 	Templates
 * 
\* ************************************************************************** */

template <typename T, typename PTR, typename INDEX>
void	runTest(PTR *ptr, INDEX len)
{
	runTest<T>(ptr, len, getRandomVoidFunction<T>());
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

template <typename T, typename PTR, typename INDEX>
void	runTest(PTR *dst, PTR *src, INDEX len)
{
	runTest<T>(dst, src, len, getRandomVoidFunction<T>());
}

template <typename T, typename PTR, typename INDEX, typename FUNC>
void	runTest(PTR *dst, PTR *src, INDEX len, FUNC f)
{
	std::cout	<< C_RESET	<< "\n[";
	::iter(dst, len, printArray<T>);
	std::cout	<<	']'	<< std::endl;
	::iter(dst, src, len, f);
	std::cout	<< '[';
	::iter(dst, len, printArray<T>);
	std::cout	<< ']'	<< std::endl;
}
