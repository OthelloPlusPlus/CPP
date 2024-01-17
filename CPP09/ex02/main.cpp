/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:46:56 by ohengelm          #+#    #+#             */
/*   Updated: 2024/01/17 18:28:51 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colors.hpp"
#include "print.hpp"

#include <cstdlib>
// std::rand()
#include <ctime>
// std::time()

#include "size_c.hpp"

typedef struct s_timeComp
{
	double	time;
	size_t	comp;
}	t_timeComp;

typedef struct s_data
{
	t_timeComp	vector;
	t_timeComp	deque;
	t_timeComp	list;
	t_timeComp	sort;
}	t_data;

template <template <typename...> class CONTAINER>
	static CONTAINER<size_c>	timedSort(int argc, char **argv, t_timeComp &data);
static void	printBefore_stdSort(int argc, char **argv, t_timeComp &data);
static void	printAfter(t_data &data, std::vector<size_c> &vector,\
						std::deque<size_c> &deque, std::list<size_c> &list);
static void	printRandom(std::string string, std::vector<size_c> &vector,\
						std::deque<size_c> &deque, std::list<size_c> &list);
static void	printInfo(t_timeComp &data, size_t size, const char *type);
static double	calculateTime(timespec &before, timespec &after);

int	main(int argc, char **argv)
{
#if __cplusplus >= 201103L
	print::subHeaderLine("Testing size: " + std::to_string(argc - 1));
#else
	print::subHeaderLine("Testing string:");
#endif
	t_data				data;
	std::vector<size_c>	vector;
	std::deque<size_c>	deque;
	std::list<size_c>	list;
	try
	{
		timespec	seed;
		clock_gettime(CLOCK_REALTIME, &seed);
		std::srand(seed.tv_nsec);

		printBefore_stdSort(argc, argv, data.sort);
		vector = timedSort<std::vector>(argc, argv, data.vector);
		deque = timedSort<std::deque>(argc, argv, data.deque);
		list = timedSort<std::list>(argc, argv, data.list);
		printAfter(data, vector, deque, list);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< C_RED	<< "Error: "
					<< C_RESET	<< e.what()
					<< std::endl;
	}
}

static void	printBefore_stdSort(int argc, char **argv, t_timeComp &data)
{
	std::vector<size_c>	vector = PmergeMe::unsorted<std::vector>(argc, argv);
	std::deque<size_c>	deque = PmergeMe::unsorted<std::deque>(argc, argv);
	std::list<size_c>	list = PmergeMe::unsorted<std::list>(argc, argv);

	printRandom("Before:", vector, deque, list);

	size_c::resetCompares();
	timespec		currentTime[2];
	clock_gettime(CLOCK_REALTIME, &currentTime[0]);
	switch (std::rand() % 3)
	{
		case 0: std::sort(vector.begin(), vector.end());break ;
		case 1: std::sort(deque.begin(), deque.end());	break ;
		case 2:	list.sort();	break ;
		default:	break;
	}
	clock_gettime(CLOCK_REALTIME, &currentTime[1]);
	data.time = calculateTime(currentTime[0], currentTime[1]);
	data.comp = size_c::getCompares();
}

template <template <typename...> class CONTAINER>
static CONTAINER<size_c>	timedSort(int argc, char **argv, t_timeComp &data)
{
	CONTAINER<size_c>	container;
	timespec		currentTime[2];

	size_c::resetCompares();
	clock_gettime(CLOCK_REALTIME, &currentTime[0]);
	container = PmergeMe::sort<CONTAINER>(argc, argv);
	clock_gettime(CLOCK_REALTIME, &currentTime[1]);
	data.time = calculateTime(currentTime[0], currentTime[1]);
	data.comp = size_c::getCompares();
	return (container);
}

static void	printAfter(t_data &data, std::vector<size_c> &vector,\
						std::deque<size_c> &deque, std::list<size_c> &list)
{
	printRandom("After:", vector, deque, list);
	print::tableHead(" std::sort()");
	printInfo(data.sort, vector.size(), "std::sort()");
	print::tableHead(" Merge-insertion");
	printInfo(data.vector, vector.size(), "<std::vector>");
	printInfo(data.deque, deque.size(), "<std::deque>");
	printInfo(data.list, list.size(), "<std::list>");
}

static void	printInfo(t_timeComp &data, size_t size, const char *type)
{
	std::string	unit("us");
	switch (static_cast<size_t>(data.time))
	{
		case 0 ... 999:	break ;
		case 1000 ... 999999:	data.time /= 1000;
								unit = "ms";
								break ;
		default:	data.time /= 1000000;
					unit = "s";
					break ;
	}
	std::cout	<< C_RESET	<< "Time to process a range of " 
				<< C_ORANGE	<< size
				<< C_RESET	<<" elements with "
				<< C_ORANGE	<< std::setw(14)	<< type
				<< C_RESET	<< ": "
				<< C_ORANGE	<< std::setw(7)	<< data.time
				<< C_RESET	<< std::setw(12)	<< (" " + unit + ", making")
				<< C_ORANGE	<< data.comp
				<< C_RESET	<< " comparisons "
				<< std::endl;
}

static void	printRandom(std::string string, std::vector<size_c> &vector,\
						std::deque<size_c> &deque, std::list<size_c> &list)
{
	std::cout	<< std::left	<< std::setw(8)	<< string;
	switch (std::rand() % 3)
	{
		case 0:	std::cout	<< std::setw(14)	<< "<std::vector>";
				PmergeMe::print(vector);
				break;
		case 1:	std::cout	<< std::setw(14)	<< "<std::deque>";
				PmergeMe::print(deque);
				break;
		case 2:	std::cout	<< std::setw(14)	<< "<std::list>";
				PmergeMe::print(list);
				break;
		default:	std::cout	<< "Error";
					break;
	}
	std::cout	<< std::endl;
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
