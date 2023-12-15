/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:21:41 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/15 21:02:29 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <cstdlib>
// std::srand()
#include <ctime>
// std::time()

double	calculateTime(timespec &before, timespec &after);

template <typename CONTAINER>
	double	timedSort(PmergeMe &merge);
	template double	timedSort<std::vector<size_t> >(PmergeMe &merge);
	template double	timedSort<std::deque<size_t> >(PmergeMe &merge);
	template double	timedSort<std::list<size_t> >(PmergeMe &merge);
template <typename CONTAINER>
	void	printTime(CONTAINER &container, double time, std::string type);

int	main(int argc, char **argv)
{
	print::subHeaderLine("Testing size: " + std::to_string(argc - 1));
	try
	{
		PmergeMe		merge(argc, argv);
		double			diff[3];

		std::srand(std::time(NULL));
		std::cout	<< std::setw(8)<< "Before:"	<< merge	<< std::endl;
		diff[0] = timedSort<std::vector<size_t> >(merge);
		diff[1] = timedSort<std::deque<size_t> >(merge);
		diff[2] = timedSort<std::list<size_t> >(merge);
		std::cout	<< std::setw(8)<< "After:"	<< merge	<< '\n'	<< std::endl;

		printTime(merge.getList(std::vector<size_t>()), diff[0], "std::vector<>");
		printTime(merge.getList(std::deque<size_t>()), diff[1], "std::deque<>");
		printTime(merge.getList(std::list<size_t>()), diff[2], "std::list<>");
	}
	catch(const std::exception &e)
	{
		std::cerr	<< C_RED	<< "Error: "
					<< C_RESET	<< e.what()
					<< std::endl;
		return (1);
	}
	return (errno);
}

template <typename CONTAINER>
double	timedSort(PmergeMe &merge)
{
	timespec	currentTime[2];

	clock_gettime(CLOCK_REALTIME, &currentTime[0]);
	merge.sort<CONTAINER>();
	clock_gettime(CLOCK_REALTIME, &currentTime[1]);
	return (calculateTime(currentTime[0], currentTime[1]));
}

double	calculateTime(timespec &before, timespec &after)
{
	double	diff(0);

	diff += static_cast<double>(after.tv_sec) * 1000000;
	diff -= static_cast<double>(before.tv_sec) * 1000000;
	diff += static_cast<double>(after.tv_nsec) / 1000;
	diff -= static_cast<double>(before.tv_nsec) / 1000;
	return (diff);
}

template <typename CONTAINER>
	void	printTime(CONTAINER &container, double time, std::string type)
{
	std::cout	<< C_RESET	<< "Time to process a range of " 
				<< C_ORANGE	<< container.size()
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
