/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:29:42 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/08 16:32:55 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <iostream>
// std::cout
#include <cstdlib>
// std::rand()
#include <ctime>
// std::time()
#include <list>
// std::list

int		testSubject(void);
void	testManual(unsigned int size);

int	main(void)
{
	print::headerLine("Exercise 02: Mutated abomination");
	std::srand(std::time(NULL));
	testSubject();
	testManual(0);
	testManual(4);
	return (0);
}

int	testSubject(void)
{
	print::subHeaderLine("Subject Tests");
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

void	testManual(unsigned int size)
{
	print::subHeaderLine("Manual test");
	std::cout	<< C_DGRAY	<< "Creating containers MutantStack and std::list"
				<< C_RESET	<< std::endl;
	MutantStack<int>	mStack;
	std::list<int>		list;

	std::cout	<< C_DGRAY	<< "Randomly filling containers for size "	<< size
				<< C_RESET	<< std::endl;
	for (unsigned int i = 0; i < size; ++i)
	{
		int	random = std::rand() % 23;
		mStack.push(random);
		list.push_back(random);
	}
	std::cout	<< C_DGRAY	<< "Creating MutantStack copy"
				<< C_RESET	<< std::endl;
	const MutantStack<int>	mStackCopy(mStack);
	std::cout	<< C_DGRAY	<< "\nPrinting contents using ::iterator"	<< '\n'
				<< C_ORANGE	<< "MS / MS (copy) / list"
				<< C_RESET	<< std::endl;
	{
		MutantStack<int>::iterator			im = mStack.begin();
		MutantStack<int>::const_iterator	imc = mStackCopy.begin();
		std::list<int>::iterator			il = list.begin();
		while (im != mStack.end())
		{
			std::cout	<< *im	<< '/'	<< *imc	<< '/'	<< *il	<< '\n';
			++im;
			++imc;
			++il;
		}
	}
	std::cout	<< C_DGRAY	<< "\nIncrementing MutantStack's values by 1 using operator[]"
				<< C_RESET	<< std::endl;
	for (size_t i = 0; i < mStack.size(); ++i)
		++mStack[i];
	std::cout	<< C_DGRAY	<< "\nPrinting contents using ::const_reverse_iterator"	<< '\n'
				<< C_ORANGE	<< "MS / MS (copy) / list"
				<< C_RESET	<< std::endl;
	{
		MutantStack<int>::const_reverse_iterator	im = mStack.rbegin();
		MutantStack<int>::const_reverse_iterator	imc = mStackCopy.rbegin();
		std::list<int>::const_reverse_iterator		il = list.rbegin();
		while (im != mStack.rend())
		{
			std::cout	<< *im	<< '/'	<< *imc	<< '/'	<< *il	<< '\n';
			++im;
			++imc;
			++il;
		}
	}
}
