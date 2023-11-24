/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:52:33 by ohengelm          #+#    #+#             */
/*   Updated: 2023/11/24 19:52:34 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "print.hpp"

#include <iostream>
// std::cout

int	testSubject(void);
void	testManual(void);

int	main(void)
{
	print::headerLine(" Start with a few functions");
	std::cout	<< "C++ version:\t"	<< __cplusplus	<< std::endl;
	testSubject();
	testManual();
}

int	testSubject(void)
{
	print::subHeaderLine("Subject Tests");
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}

void	testManual(void)
{
	print::subHeaderLine("Manual Tests (C++98)");
	std::string	lorem("ipsum");
	std::string ipsum("lorem");

	::swap(lorem, ipsum);
	std::cout	<< lorem	<< ' '	<< ipsum	<< std::endl;
	int	a = 42;
	int	b = 23;

	::swap(a, b);
	std::cout	<< a	<< "\ta\n"
				<< b	<< "\tb\n"
				<< ::min(a, b) << "\t::min(a, b)\n"
				<< ::max(a, b)	<< "\t::max(a, b)\n"
				<< std::flush;
	print::subHeaderLine("Manual Tests (C++11 and later)");
#if __cplusplus >= 201103L
	int	c = -1;
	int	d = 0;
	int	e = 1;

	std::cout	<< ::min(a)	<< "\t::min(a)\n"
				<< ::min(b, a, c, e, d)	<< "\t::min(b, a, c, e, d)\n"
				<< ::max(b)	<< "\t::max(b)\n"
				<< ::max(b, a, c, e, d)	<< "\t::max(b, a, c, e, d)\n"
				<< ::min(&a, &b)	<< "\t::min(&d, &e)\n"
				<< ::max(&a, &b)	<< "\t::max(&d, &e)\n"
				<< std::flush;
#endif
}