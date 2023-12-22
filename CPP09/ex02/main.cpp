/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:21:41 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/22 19:19:08 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <vector>
// std::vector
#include <deque>
// std::deque
#include <list>
// std::list
#include <cstdlib>
// std::srand()
#include <ctime>
// std::time()

static void	printBefore(int argc, char **argv);
static void	printRandom(const char *string, \
						PmergeMe<std::vector<size_t> > &vector, \
						PmergeMe<std::deque<size_t> > &deque, \
						PmergeMe<std::list<size_t> > &list);
template <typename CONTAINER>
	static void	timedSort(CONTAINER &container, int argc, char **argv, const char *type);
static double		calculateTime(timespec &before, timespec &after);
static void			printTime(int size, double time, std::string type);

/** ************************************************************************ **\
 * 
 * 	Main
 * 
\* ************************************************************************** */

int	main(int argc, char **argv)
{
#if __cplusplus >= 201103L
	print::subHeaderLine("Testing size: " + std::to_string(argc - 1));
#else
	print::subHeaderLine("Testing string:");
#endif
	try
	{
		PmergeMe<std::vector<size_t> >	vector;
		PmergeMe<std::deque<size_t> >	deque;
		PmergeMe<std::list<size_t> >	list;

		timespec	seed;
		clock_gettime(CLOCK_REALTIME, &seed);
		std::srand(seed.tv_nsec);

		printBefore(argc, argv);
		timedSort(vector, argc, argv, "std::vector");
		timedSort(deque, argc, argv, "std::deque");
		timedSort(list, argc, argv, "std::list");
		printRandom("After:", vector, deque, list);
	}
	catch(const std::exception &e)
	{
		std::cerr	<< C_RED	<< "Error: "
					<< C_RESET	<< e.what()
					<< std::endl;
		return (1);
	}
	return (0);
}

/** ************************************************************************ **\
 * 
 * 	Static Functions
 * 
\* ************************************************************************** */

static void	printBefore(int argc, char **argv)
{
	PmergeMe<std::vector<size_t> >	vector;
	PmergeMe<std::deque<size_t> >	deque;
	PmergeMe<std::list<size_t> >	list;

	vector.parseInput(argc, argv);
	deque.parseInput(argc, argv);
	list.parseInput(argc, argv);
	printRandom("Before:", vector, deque, list);
}

static void	printRandom(const char *string, \
					PmergeMe<std::vector<size_t> > &vector, \
					PmergeMe<std::deque<size_t> > &deque, \
					PmergeMe<std::list<size_t> > &list)
{
	std::cout	<< std::setw(8)	<< string;
	switch (std::rand() % 3)
	{
		case 0:	std::cout	<< vector	<< " (std::vector)";	break ;
		case 1: std::cout	<< deque	<< " (std::deque)";	break ;
		case 2:	std::cout	<< list		<< " (std::list)";	break ;
		default:	std::cout	<< "Error";	break ;
	}
	std::cout	<< std::endl;
}

template <typename CONTAINER>
static void	timedSort(CONTAINER &container, int argc, char **argv, const char *type)
{
	timespec	currentTime[2];

	clock_gettime(CLOCK_REALTIME, &currentTime[0]);
	container.sort(argc, argv);
	clock_gettime(CLOCK_REALTIME, &currentTime[1]);
	printTime(container.getContainer().size(), calculateTime(currentTime[0], currentTime[1]), type);
}

static double	calculateTime(timespec &before, timespec &after)
{
	double	diff(0);

	diff += static_cast<double>(after.tv_sec) * 1000000;
	diff -= static_cast<double>(before.tv_sec) * 1000000;
	diff += static_cast<double>(after.tv_nsec) / 1000;
	diff -= static_cast<double>(before.tv_nsec) / 1000;
	return (diff);
}

static void	printTime(int size, double time, std::string type)
{
	std::cout	<< C_RESET	<< "Time to process a range of " 
				<< C_ORANGE	<< size
				<< C_RESET	<<" elements with "
				<< C_ORANGE	<< std::setw(14)	<< type
				<< C_RESET	<< ": ";
	std::string	unit(" us");
	switch (static_cast<int>(time))
	{
		case 0 ... 999:	break ;
		case 1000 ... 999999:	time /= 1000;
								unit = " ms";
								break ;
		default:	time /= 1000000;
					unit = " s";
					break ;
	}
	std::cout	<< C_ORANGE	<< time
				<< C_RESET	<< unit
				<< std::endl;
}
