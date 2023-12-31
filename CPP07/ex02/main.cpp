/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:14:33 by ohengelm          #+#    #+#             */
/*   Updated: 2023/11/30 14:14:35 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "print.hpp"

#include <iostream>
// std::cout
#include <cstdlib>
// std::rand

#define MAX_VAL 750

int		testSubject(void);
void	testEmpty(void);
void	testArrayInt(unsigned int size);
void	testArrayString(void);

int	main(void)
{
	print::headerLine("Exercise 02: Array");
	testSubject();
	testEmpty();
	testArrayInt(4);
	testArrayString();
	return (0);
}

int	testSubject(void)
{
	print::subHeaderLine("42's provided tests");
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		print::note("Expected error");
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		print::note("Expected error");
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

void	testEmpty(void)
{
	print::subHeaderLine("Testing empty constructer");
	try
	{
		Array<int>	empty;
		std::cout	<< "empty.size()\t"	<< empty.size()	<< std::endl;
		std::cout	<< empty[0]	<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testArrayInt(unsigned int size)
{
	print::subHeaderLine("Testing <int> Array");
	Array<int>	base(size);
	for (int i = 0; i < static_cast<int>(base.size()); ++i)
		base[i] = i;
	Array<int>	equal = base;
	Array<int>	copy(base);
	for (int i = 0; i < static_cast<int>(base.size()); ++i)
		base[i] = std::rand() % 1000000;
	std::cout	<< "base.size()\t"	<< base.size()	<< std::endl;
	try
	{
		print::tableHead("i\tbase\tequal\tcopy");
		for (int i = 0; i <= static_cast<int>(base.size()); i++)
			std::cout	<< i << '\t'
						<< base[i] << '\t'
						<< equal[i] << '\t'
						<< copy[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< C_RED	<< e.what() 
					<< C_RESET	<< std::endl;
	}
}

void	testArrayString(void)
{
	print::subHeaderLine("Testing <std::string> Array");
	Array<std::string>	array(5);

	array[0] = "Lorem";
	array[1] = "ipsum";
	array[2] = "dolor";
	array[3] = "sit";
	array[4] = "amet";
	for (unsigned int i = 0; i < array.size(); ++i)
		array[i] += '!';
	std::cout	<< "array.size()\t"	<< array.size()	<< std::endl;
	print::tableHead("array[i]\tstd::string");
	for (unsigned int i = 0; i < array.size(); ++i)
		std::cout	<< "array["	<< i	<< "]\t"	<< array[i]	<< '\n';
	std::cout	<< std::flush;
}
