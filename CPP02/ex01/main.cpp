/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:42:09 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/31 19:15:11 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"
#include "print.hpp"

#include <iostream>
// std::
#include <iomanip>
// std::setw()

#define SIZE_NAME	9

void	subject_ex00(void);
void	subject_ex01(void);
void	tests_ex01(void);
void	subject_ex02(void);
void	tests_ex02(void);

void	print_float_value(std::string name, Fixed const &point);

int main(void)
{
	// subject_ex00();
	subject_ex01();
	tests_ex01();
	// subject_ex02();
	// tests_ex02();
	return (0);
}

void	subject_ex00(void)
{
	print::headerLine("Exercise 00: My First Class in Orthodox Canonical Form");
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

void	subject_ex01(void)
{
	print::headerLine("Exercise 01: Towards a more useful fixed-point number class");
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void	tests_ex01(void)
{
	print::headerLine("Exercise 01: Custom tests");
	Fixed a;
	Fixed const b( 255 );
	Fixed const c( 23.23f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	print_float_value("a", a);
	print_float_value("b", b);
	print_float_value("c", c);
	print_float_value("d", d);
}

void	print_float_value(std::string name, Fixed const &point)
{
	print::subHeaderLine(name);
	std::cout	<< C_GRAY	<< std::setw(SIZE_NAME)	<< "value:"
				<< C_RESET	<< point
				<< C_RESET	<< "\n"
				<< C_GRAY	<< std::setw(SIZE_NAME)	<< "integer:"
				<< C_RESET	<< point.toInt()
				<< C_RESET	<< "\n"
				<< C_GRAY	<< std::setw(SIZE_NAME)	<< "raw:"
				<< C_RESET	<< point.toRaw()
				<< C_RESET	<< std::right	<< std::endl;
}

void	subject_ex02(void)
{
	print::headerLine("Exercise 02: Now we’re talking");
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
}

void	tests_ex02(void)
{
	print::headerLine("Exercise 02: Custom tests");
	Fixed a(42.23f);
	Fixed b(2);
	Fixed c;

	print::subHeaderLine("Starting values");
	std::cout	<< "a\t"	<< a	<< "\n"
				<< "b\t"	<< b	<< "\n"
				<< "c\t"	<< c
				<< std::endl;
	print::subHeaderLine("Arithmic operators    + - * /");
	std::cout	<< "a + b\t"	<< a + b	<< "\n"
				<< "a - b\t"	<< a - b	<< "\n"
				<< "a * b\t"	<< a * b	<< "\n"
				<< "a / b\t"	<< a / b
				<< std::endl;
	print::subHeaderLine("Relational operators    > < >= <= == !=");
	std::cout	<< ">\t<\t>=\t<=\t==\t!="
				<< std::endl;
	std::cout	<< (a > a)	<< (a > b)	<< (b > a)	<< "\t"
				<< (a < a)	<< (a < b)	<< (b < a)	<< "\t"
				<< (a >= a)	<< (a >= b)	<< (b >= a)	<< "\t"
				<< (a <= a)	<< (a <= b)	<< (b <= a)	<< "\t"
				<< (a == a)	<< (a == b)	<< (b == a)	<< "\t"
				<< (a != a)	<< (a != b)	<< (b != a)
				<< std::endl;
	std::cout	<< "010\t"
				<< "001\t"
				<< "110\t"
				<< "101\t"
				<< "100\t"
				<< "011"
				<< std::endl;
	print::subHeaderLine("Assignment operators    i++ i--");
	std::cout	<< "a\t"	<<	a	<< "\n"
				<< "++a\t"	<<	++a	<< "\t++\n"
				<< "a\t"	<<	a	<< "\n"
				<< "a++\t"	<<	a++	<< "\n"
				<< "a\t"	<<	a	<< "\t++\n"
				<< "--a\t"	<<	--a	<< "\t--\n"
				<< "a\t"	<<	a	<< "\n"
				<< "a--\t"	<<	a--	<< "\n"
				<< "a\t"	<<	a	<< "\t--"
				<< std::endl;
	print::subHeaderLine("Comparisons            min max");
	std::cout	<< "Fixed::min(a, b)\t"	<< Fixed::min(a, b)	<< std::endl;
	std::cout	<< "Fixed::max(a, b)\t"	<< Fixed::max(a, b)	<< std::endl;
}
