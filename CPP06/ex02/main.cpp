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

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <cstdlib>
// std::srand
#include <ctime>
// std::time

#define PRINTW 16

void	test(Base *test);
Base *generate(void);
void	identify(Base *p);

int	main(void)
{
	print::headerLine("Exercise 02: Identify real type");
	std::srand(std::time(nullptr));

	print::subHeaderLine("Manual Tests");
	std::cout	<< std::setw(PRINTW)	<< "Identity true:"	<< "A\n";
	test(new A);
	std::cout	<< std::setw(PRINTW)	<< "Identity true:"	<< "B\n";
	test(new B);
	std::cout	<< std::setw(PRINTW)	<< "Identity true:"	<< "C\n";
	test(new C);
	print::subHeaderLine("Random Tests");
	for (int i = 0; i < 4; ++i)
		test(nullptr);

	return (0);
}

void	test(Base *test)
{
	if (!test)
		test = generate();

	std::cout	<< std::setw(PRINTW)	<< "Identify Base*:";
	identify(test);
	std::cout	<< '\n'
				<< std::setw(PRINTW)	<< "Identify Base&:";
	identify(&(*test));
	std::cout	<< '\n'	<< std::endl;
	delete test;
}

Base *generate(void)
{
	std::cout	<< std::setw(PRINTW)	<< "Identity true:";
	switch (std::rand() % 4)
	{
		case 0:		std::cout	<< "A\n";	return (new A);
		case 1:		std::cout	<< "B\n";	return (new B);
		case 2:		std::cout	<< "C\n";	return (new C);
		default:	std::cout	<< "?\n";	return (nullptr);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout	<< 'A';
	else if (dynamic_cast<B *>(p))
		std::cout	<< 'B';
	else if (dynamic_cast<C *>(p))
		std::cout	<< 'C';
	else
		std::cout	<< '?';
}

void	identify(Base &p)
{
	for (int i = 0; i < 4; ++i)
	{
		try
		{
			switch (i)
			{
				case 0:	(void)dynamic_cast<A &>(p);
						std::cout	<< 'A';
						return ;
				case 1:	(void)dynamic_cast<B &>(p);
						std::cout	<< 'B';
						return ;
				case 2:	(void)dynamic_cast<C &>(p);
						std::cout	<< 'C';
						return ;
				default:	std::cout	<< '?';
							return ;
			}
		}
		catch(const std::bad_cast &e)
		{}
		catch(const std::exception& e)
		{
			std::cerr	<< C_RED	<< "Error: "
						<< C_RESET	<< e.what()	<< std::endl;
		}
	}
}
