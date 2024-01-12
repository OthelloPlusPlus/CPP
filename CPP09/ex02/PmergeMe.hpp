
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
//std::vector
# include <list>
//std::list
# include <deque>
//std::deque

namespace PmergeMe
{
	template <template <typename...> class CONTAINER>
	CONTAINER<int>	sort(int argc, char **argv);

	template <template <typename...> class CONTAINER>
	CONTAINER<int>	sort(CONTAINER<int> container);

	template <template <typename...> class CONTAINER>
	CONTAINER<int>	unsorted(int argc, char **argv);

	template <typename CONTAINER>
	void	print(CONTAINER &container);
}

#include "PmergeMe.tpp"

#endif
