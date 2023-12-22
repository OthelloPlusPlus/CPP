/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:20:43 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/22 19:54:57 by ohengelm         ###   ########.fr       */
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
// std::min_element()

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

template <typename CONTAINER>
PmergeMe<CONTAINER>::PmergeMe(void)
{
	// std::cout	<< C_DGREEN	<< "Default constructor "
	// 			<< C_GREEN	<< "PmergeMe"
	// 			<< C_DGREEN	<< " called."
	// 			<< C_RESET	<< std::endl;
}

template <typename CONTAINER>
PmergeMe<CONTAINER>::PmergeMe(const PmergeMe &src)
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

template <typename CONTAINER>
PmergeMe<CONTAINER>::~PmergeMe(void)
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

/**
 * parses and sorts passed arguments.
*/
template <typename CONTAINER>
void	PmergeMe<CONTAINER>::sort(int argc, char **argv)
{
	int			dangler(-1);

	this->parseInput(argc, argv);
	if (container.size() <= 1)
		return ;
	if (container.size() % 2)
		dangler = this->extractDangler();
	this->splitContainer();
	this->largestOnTop();
	this->sortHighAscending();
	this->priorityInsert();
	if (dangler >= 0)
		this->container.insert(std::upper_bound(this->container.begin(), this->container.end(), dangler), dangler);
	this->low.clear();
}

/**
 * Clears containers, parses arguments and stores them in container.
 * Made public for demonstration purposes.
*/
template <typename CONTAINER>
void	PmergeMe<CONTAINER>::parseInput(int argc, char **argv)
{
	this->container.clear();
	this->low.clear();
	for (int i = 1; i < argc; ++i)
		this->container.push_back(this->convertToInt(argv[i]));
}

template <typename CONTAINER>
int	PmergeMe<CONTAINER>::convertToInt(const char *arg) const
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

template <typename CONTAINER>
int	PmergeMe<CONTAINER>::extractDangler(void)
{
	int	dangler = this->container.back();
	this->container.erase(--this->container.end());
	return (dangler);
}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::splitContainer(void)
{
	for (typename CONTAINER::iterator i = this->container.begin(); i != this->container.end();)
	{
		++i;
		if (i == this->container.end())
			break ;
		this->low.push_back(*i);
		i = this->container.erase(i);
	}
}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::largestOnTop(void)
{
	for (typename CONTAINER::iterator i = this->container.begin(), j = this->low.begin(); i != this->container.end(); ++i, ++j)
		if (*i < *j)
			std::swap(*i, *j);
}

// https://www.youtube.com/watch?v=wqibJMG42Ik&t=283s
// https://github.com/MyNameIsTrez/cpp/blob/master/09/ex02/PmergeMe.py

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::sortHighAscending(void)
{
	typename CONTAINER::iterator posHigh = this->container.begin();
	typename CONTAINER::iterator posLow = this->low.begin();

	for (; posHigh != this->container.end(); ++posHigh, ++posLow)
	{
		typename CONTAINER::iterator nextHigh = std::min_element(posHigh, this->container.end());
		typename CONTAINER::iterator nextLow = posLow;
		for (typename CONTAINER::iterator i = posHigh; i != nextHigh && i != this->container.end(); ++i)
			++nextLow;
		if (nextHigh != this->container.end() && nextLow != this->low.end())
		{
			std::swap(*posHigh, *nextHigh);
			std::swap(*posLow, *nextLow);
		}
	}
}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::priorityInsert(void)
{
	typename CONTAINER::const_iterator	upper;
	typename CONTAINER::const_iterator	lower;
	size_t	JH[2] = {0, 1};

	upper = this->low.begin();
	lower = upper;
	this->container.insert(this->container.begin(), *upper);
	for (size_t i = 1; i < this->low.size();)
	{
		for (typename CONTAINER::const_iterator pos = upper; pos != lower; --pos)
		{
			this->container.insert(std::upper_bound(this->container.begin(), this->container.end(), *pos), *pos);
			++i;
		}
		if (i >= this->low.size())
			break ;
		lower = upper;
		for (size_t j = JH[1] - JH[0]; j > 0; --j)
			if (upper != this->low.end())
				++upper;
			else
				break ;
		if (upper == this->low.end())
			--upper;
		JH[0] = JH[0] * 2 + JH[1];
		std::swap(JH[0], JH[1]);
	}
}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::printContents(void)
{
	std::cout	<< "High: ";
	for (typename CONTAINER::const_iterator i = this->container.begin(); i != this->container.end(); ++i)
		std::cout	<< *i	<< ' ';
	std::cout	<< '\n'
				<< "low:  ";
	for (typename CONTAINER::const_iterator i = this->low.begin(); i != this->low.end(); ++i)
		std::cout	<< *i	<< ' ';
	std::cout	<< std::endl;
}

// /** ************************************************************************ **\
//  * 
//  * 	Operators
//  * 
// \* ************************************************************************** */

template <typename CONTAINER>
PmergeMe<CONTAINER>	&PmergeMe<CONTAINER>::operator=(const PmergeMe<CONTAINER> &src)
{
	if (this == &src)
		return (*this);
	this->container = src.container;
	this->low = src.low;
	return (*this);
}

template <typename CONTAINER>
std::ostream	&operator<<(std::ostream &out, PmergeMe<CONTAINER> &src)
{
	const CONTAINER	&container = src.getContainer();

	typename CONTAINER::const_iterator i = container.begin();
	for (size_t count = 0; i != container.end(); ++i, ++count)
	{
		if (count >= 7)
		{
			out	<< "[...]";
			break ;
		}
		out	<< *i	<< ' ';
	}
	return (out);
}
