#include <algorithm>
// std::upper_bound()
#include <iostream>
// std::cout

namespace
{
/** ************************************************************************ **\
 * 
 * 	Parsing
 * 
\* ************************************************************************** */

	int	convertToInt(const char *arg)
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

	template <typename CONT>
	CONT	parseInput(int argc, char **argv)
	{
		CONT	container;
		for (int i = 1; i < argc; ++i)
			container.push_back(::convertToInt(argv[i]));
		return (container);
	}

/** ************************************************************************ **\
 * 
 * 	Copying
 * 
\* ************************************************************************** */

	template <typename PAIR, typename CONT>
	PAIR	copyIntoPaired(CONT container)
	{
		PAIR	paired;
		for (typename CONT::iterator i = container.begin(); i != container.end(); ++i)
			paired.push_back(CONT{*i});
		return (paired);
	}

/** ************************************************************************ **\
 * 
 * 	Pairing
 * 
\* ************************************************************************** */

	template <typename CONT>
	void	setIterators(CONT &container, typename CONT::iterator &pos, typename CONT::iterator &next, size_t adv)
	{
		pos = container.begin();
		std::advance(pos, adv);
		next = pos;
		++next;
	}

	template <typename CONT, typename PAIR>
	bool	pairUpAndSortUpper(CONT &container, PAIR &paired)
	{
		typename CONT::iterator	iCont;
		typename CONT::iterator iContNext;
		typename PAIR::iterator	iPair;
		typename PAIR::iterator iPairNext;
		size_t	size = paired.begin()->size();

		for (size_t i = 0; i <= container.size(); ++i)
		{
			::setIterators(container, iCont, iContNext, i);
			::setIterators(paired, iPair, iPairNext, i);
			if (iContNext == container.end() ||\
				iPairNext == paired.end() ||\
				iPairNext->size() != size)
				break ;
			if (*iCont < *iContNext)
			{
				std::swap(*iCont, *iContNext);
				std::swap(*iPair, *iPairNext);
			}
			iPair->insert(iPair->end(), iPairNext->begin(), iPairNext->end());
			container.erase(iContNext);
			iPairNext->clear();
			paired.erase(iPairNext);
		}
		if (iCont != container.end())
			container.erase(iCont);
		return (paired.begin()->size() != size);
	}

/** ************************************************************************ **\
 * 
 * 	Insertion
 * 
\* ************************************************************************** */

	template <typename CONT, typename PAIR>
	bool	setJacobHalIterator(size_t size, int JH[2],\
								CONT &container, PAIR &paired,\
								typename CONT::iterator &iCont, typename PAIR::iterator	&iPair)
	{
		iCont = container.begin();
		iPair = paired.begin();
		int	count = 0;
		for (int steps = JH[1] - JH[0]; iCont != container.end(); ++iCont, ++iPair)
		{
			if (iPair->size() < size)
				continue;
			++count;
			--steps;
			if (steps <= 0)
				break ;
		}
		JH[0] = JH[0] * 2 + JH[1];
		std::swap(JH[0], JH[1]);
		return (count > 0);
	}

	template <typename CONTIT, typename CONT>
	CONT	splitContainer(CONTIT &insert, CONT &paired)
	{
		CONT	newPair;

		while (insert != paired.end())
		{
			newPair.push_back(*insert);
			insert = paired.erase(insert);
		}
		return (newPair);
	}

	template <typename CONT, typename PAIR>
	void	binaryInsertion(CONT &container, PAIR &paired)
	{
		typename CONT::iterator	iCont;
		typename PAIR::iterator	iPair;
		int		JH[2] = {0, 1};
		size_t	size = paired.begin()->size();

		while (::setJacobHalIterator(size, JH, container, paired, iCont, iPair))
		{
			for (; iCont != --container.begin(); --iCont, --iPair)
			{
				if (iPair->size() != size)
				{
					if (iCont != container.begin())
						break ;
					else
						continue ;
				}
				auto	insert = iPair->begin();
				std::advance(insert, size / 2);
				auto	insertContainer = std::upper_bound(container.begin(), iCont, *insert);
				auto	insertPair = paired.begin();
				for (auto i = container.begin(); i != insertContainer && i != container.end(); ++i)
					++insertPair;
				container.insert(insertContainer, *insert);
				paired.insert(insertPair, ::splitContainer(insert, *iPair));
			}
		}
	}

/** ************************************************************************ **\
 * 
 * 	Trailing
 * 
\* ************************************************************************** */

	template <typename CONT, typename PAIR>
	void	addTrailer(CONT &container, PAIR &paired)
	{
		if (paired.size() <= container.size())
			return ;
		typename PAIR::iterator	iPair = paired.begin();
		std::advance(iPair, container.size());
		while (iPair != paired.end())
		{
			while (!iPair->empty())
			{
				typename CONT::iterator	pos = std::upper_bound(container.begin(), container.end(), *iPair->begin());
				container.insert(pos, *iPair->begin());
				iPair->erase(iPair->begin());
			}
			iPair = paired.erase(iPair);
		}
	}
}

/** ************************************************************************ **\
 * 
 * 	PmergeMe
 * 
\* ************************************************************************** */

/**
 * 
*/
template <template <typename...> class CONTAINER>
CONTAINER<int>	PmergeMe::sort(int argc, char **argv)
{
	CONTAINER<int>	container;

	container = ::parseInput<CONTAINER<int>>(argc, argv);
	return (PmergeMe::sort(container));
}

template <template <typename...> class CONTAINER>
CONTAINER<int>	PmergeMe::sort(CONTAINER<int> container)
{
	CONTAINER<CONTAINER<int>>	paired;

	if (container.size() <= 1)
		return (container);
	paired = ::copyIntoPaired<CONTAINER<CONTAINER<int>>>(container);
	while (container.size() > 1)
		if (!::pairUpAndSortUpper(container, paired))
			break ;
	while (paired.size() && paired.begin()->size() > 1)
		::binaryInsertion(container, paired);
	::addTrailer(container, paired);
	return (container);
}

template <template <typename...> class CONTAINER>
CONTAINER<int>	PmergeMe::unsorted(int argc, char **argv)
{
	return (::parseInput<CONTAINER<int>>(argc, argv));
}

template <typename CONTAINER>
void	PmergeMe::print(CONTAINER &container)
{
	typename CONTAINER::const_iterator i = container.begin();
	if (i != container.end())
		std::cout	<< *i;
	else
		return ;
	++i;
	size_t	max = 8;
	for (size_t count = max - 1; i != container.end() && count > 0; ++i, --count)
		if (count > 1 || (count == 1 && container.size() == max))
			std::cout	<< ' '	<< *i;
		else
			std::cout	<< " [...]";
}
