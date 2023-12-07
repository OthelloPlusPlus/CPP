/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:58:37 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/07 18:53:31 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "print.hpp"

#include <cstdlib>
// std::srand()
#include <ctime>
// std::time()
#include <iostream>
// std::cout
#include <iomanip>
// std::setw()

int		testSubject(void);
void	testManualSequential(unsigned int size);
void	testManualRandom(unsigned int fill, unsigned int size);
void	testPrint(Span &span);

int	main(void)
{
	print::headerLine("Exercise 01: Span");
	std::srand(std::time(NULL));

	testSubject();
	testManualSequential(3);
	testManualRandom(0, 0);
	testManualRandom(1, 1);
	testManualRandom(2, 2);
	testManualRandom(23, 23);
	testManualRandom(2, 23);
	testManualRandom(23, 3);
	testManualRandom(0x3fff, 0x3fff);
	testManualRandom(0xffffff, 0xffffff);
	return (0);
}

int	testSubject(void)
{
	print::subHeaderLine("Subject Tests");
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return 0;
}

void	testManualSequential(unsigned int size)
{
	print::subHeaderLine("Manual test");
	int	num(99);

	Span	span(size);
	try
	{
		for (unsigned int i = 0; i <= size; ++i)
		{
			num -= i;
			span.addNumber(num);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	testPrint(span);
}

void	testManualRandom(unsigned int fill, unsigned int size)
{
	print::subHeaderLine("Random test");
	std::cout	<< std::setw(10)	<< "test:"	<< fill	<< '/'	<< size	<< std::endl;;
	if (size > 0xffffff && fill > 0xffffff)
	{
		std::cout	<< C_RED	<< "Error: "
					<< C_RESET	<< "Too big to test safely"
					<< std::endl;
		return ;
	}
	Span span(size);

	try
	{
		span.addNumbers(fill);
	}
	catch(const std::exception &e)
	{
		std::cerr	<< C_RED	<< "Error: "
					<< C_RESET	<< e.what()
					<< std::endl;
	}
	testPrint(span);
}

void	testPrint(Span &span)
{
	print::tableHead("Output");
	for (int i = 0; ; ++i)
	{
		try
		{
			switch (i)
			{
			case 0:	std::cout	<< std::setw(10)	<< "size:"
								<< span.size()	<< '/'	<< span.maxsize()	<< std::endl;
					break ;
			case 1:	std::cout	<< std::setw(10)	<< "shortest:"
								<< span.shortestSpan()	<< std::endl;
					break ;
			case 2:	std::cout	<< std::setw(10)	<< "longest:"
								<< span.longestSpan()	<< std::endl;
					break ;
			case 3:	if (span.size() < 100)
					{
						std::cout	<< std::setw(10)	<< "content:";
						span.printSpan();
					}
					break ;
			default:	return ;
			}
		}
		catch(const std::exception &e)
		{
			std::cerr	<< C_RED	<< "Error: "
						<< C_RESET	<< e.what()
						<< std::endl;
		}
	}
}
