#include "PmergeMe.hpp"
#include "colors.hpp"
#include "print.hpp"

#include <cstdlib>
// std::rand()
#include <ctime>
// std::time()

void			printBefore(int argc, char **argv);
template <template <typename...> class CONTAINER>
	CONTAINER<int>	timedSort(int argc, char **argv, const char *type);
void			printRandom(std::string string, std::vector<int> &vector, std::deque<int> &deque, std::list<int> &list);
static double	calculateTime(timespec &before, timespec &after);

int	main(int argc, char **argv)
{
#if __cplusplus >= 201103L
	print::subHeaderLine("Testing size: " + std::to_string(argc - 1));
#else
	print::subHeaderLine("Testing string:");
#endif
	std::vector<int>	vector;
	std::deque<int>		deque;
	std::list<int>		list;
	try
	{
		std::srand(time(NULL));
		printBefore(argc, argv);
		vector = timedSort<std::vector>(argc, argv, "<std::vector>");
		deque = timedSort<std::deque>(argc, argv, "<std::deque>");
		list = timedSort<std::list>(argc, argv, "<std::list>");
		printRandom("After ", vector, deque, list);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< C_RED	<< "Error: "
					<< C_RESET	<< e.what()
					<< std::endl;
	}
}

void	printBefore(int argc, char **argv)
{
	std::vector<int>	vector = PmergeMe::unsorted<std::vector>(argc, argv);
	std::deque<int>		deque = PmergeMe::unsorted<std::deque>(argc, argv);
	std::list<int>		list = PmergeMe::unsorted<std::list>(argc, argv);

	printRandom("Before", vector, deque, list);
}

template <template <typename...> class CONTAINER>
CONTAINER<int>	timedSort(int argc, char **argv, const char *type)
{
	CONTAINER<int>	container;
	timespec		currentTime[2];

	clock_gettime(CLOCK_REALTIME, &currentTime[0]);
	container = PmergeMe::sort<CONTAINER>(argc, argv);
	clock_gettime(CLOCK_REALTIME, &currentTime[1]);
	std::cout	<< C_RESET	<< "Time to process a range of " 
			<< C_ORANGE	<< container.size()
			<< C_RESET	<<" elements with "
			<< C_ORANGE	<< std::setw(14)	<< type
			<< C_RESET	<< ": ";
	std::string	unit(" us");
	double	time = calculateTime(currentTime[0], currentTime[1]);
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
	return (container);
}

void	printRandom(std::string string, std::vector<int> &vector, std::deque<int> &deque, std::list<int> &list)
{
	std::cout	<< std::left	<< std::setw(7)	<< string;
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
