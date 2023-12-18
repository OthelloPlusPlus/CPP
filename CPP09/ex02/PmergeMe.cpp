/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 19:20:43 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/08 19:20:43 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colors.hpp"

#include <iostream>
// std::cout
#include <iostream>
//std::ostream
#include <cstdlib>
// std::atoi()
// std::rand()
#include <algorithm>
// std::upper_bound()

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int	value = this->convertToInt(argv[i]);
		this->vector.push_back(value);
		this->deque.push_back(value);
		this->list.push_back(value);
	}
	// std::cout	<< C_DGREEN	<< "Default constructor "
	// 			<< C_GREEN	<< "PmergeMe"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
	// std::cout	<< C_DGREEN	<< "Copy constructor "
	// 			<< C_GREEN	<< "PmergeMe"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

PmergeMe::~PmergeMe(void)
{
	// std::cout	<< C_RED	<< "Deconstructor "
	// 			<< C_RED	<< "PmergeMe"
	// 			<< C_DRED	<< " called"
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

template void PmergeMe::sort<std::vector<size_t> >();
template void PmergeMe::sort<std::deque<size_t> >();
template void PmergeMe::sort<std::list<size_t> >();

template <typename CONTAINER>
void PmergeMe::sort(void)
{
	CONTAINER	&container = this->getContainer(CONTAINER());
	if (container.size() <= 1)
		return ;
	size_t		split = (container.size() + 1) / 2 + ((container.size() + 1) / 2) % 2;
	CONTAINER	array[split];

	for (size_t i = 0; !container.empty(); ++i)
	{
		array[i / 2].push_back(container.front());
		container.erase(container.begin());
	}
	for (size_t i = 0; i < split; ++i)
		if (!array[i].empty() && array[i].front() > array[i].back())
			std::swap(array[i].front(), array[i].back());
	while (split > 1)
	{
		split = (split / 2) + (split % 2);
		for (size_t i = 0; i < split; ++i)
			array[i] = this->merge(array[i * 2], array[i * 2 + 1]);
	}
	container = array[0];
}

template <typename CONTAINER>
CONTAINER	&PmergeMe::merge(CONTAINER &first, CONTAINER &second) const
{
	for (typename CONTAINER::iterator pos = first.begin(); !second.empty();)
	{
		pos = std::upper_bound(pos, first.end(), second.front());
		pos = first.insert(pos, second.front());
		second.erase(second.begin());
	}
	return (first);
}

template <typename CONTAINER>
std::ostream	&PmergeMe::printRandom(std::ostream &out, const CONTAINER &container)
{
	typename CONTAINER::const_iterator i = container.begin();
	for (int count = 1; i != container.end(); ++i, ++count)
	{
		if (count > 7)
		{
			out	<< "[...]";
			break ;
		}
		out << *i << ' ';
	}
	return (out);
}

int	PmergeMe::convertToInt(const char *arg) const
{
	std::string	validate(arg);
	int	value;

	if (validate.empty())
		throw (std::invalid_argument("Empty argument passed"));
	if (validate.find_first_of("1234567890") == std::string::npos ||\
		validate.find_first_not_of("1234567890-+") != std::string::npos)
		throw (std::invalid_argument("Invalid number passed: " + validate));
	value = std::atoi(arg);
	if (value < 0)
		throw (std::invalid_argument("Negative number passed: " + validate));
	return (value);
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

PmergeMe	&PmergeMe::operator=(const PmergeMe &src)
{
	if (this == &src)
		return (*this);
	this->vector = src.vector;
	this->deque = src.deque;
	this->list = src.list;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, PmergeMe &src)
{
	switch (std::rand() % 3)
	{
		case 0:	return (src.printRandom(out, src.getConstContainer(std::vector<size_t>())));
		case 1:	return (src.printRandom(out, src.getConstContainer(std::list<size_t>())));
		case 2:	return (src.printRandom(out, src.getConstContainer(std::deque<size_t>())));
		default:	return (out	<< "Error");
	}
	return (out);
}
