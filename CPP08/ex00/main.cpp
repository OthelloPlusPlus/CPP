/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:36:22 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/07 14:58:08 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "wrappers.hpp"
#include "colors.hpp"
#include "print.hpp"

#include <cstdlib>
// std::srand()
#include <ctime>
// std::time()
#include <typeinfo>
// typeid()

#include <vector>
// std::vector
#include <deque>
// std::deque
#include <list>
// std::list
#include <set>
// std::set
// std::multiset
#if __cplusplus >= 201103L
# include <array>
// std::array
# include <forward_list>
// std::forward_list
#endif

#define EF_SIZE		23
#define EF_SEARCH	23
#define EF_MODULO	42

template <typename T, typename FUNC>
void	runTest(FUNC f, std::string name);
template <typename T, typename FUNC>
T	createArray(FUNC f, unsigned int size);

int	main(void)
{
	print::headerLine("Exercise 00: Easy find");
	print::note("boost:: for pretty typename");
	std::cout	<< std::endl;
	std::srand(std::time(NULL));

	print::subHeaderLine("Sequence Containers");
	runTest<std::vector<int> >(push_backWrapper<std::vector<int>, int>, "std::vector<int>");
	runTest<std::deque<int> >(push_backWrapper<std::deque<int>, int>, "std::deque<int>");
	runTest<std::list<int> >(push_backWrapper<std::list<int>, int>, "std::list<int>");
#if __cplusplus >= 201103L
	runTest<std::array<int, EF_SIZE> >([](auto &container, int value){static int i = 0;container[i++] = value;}, "std::array<int, EF_SIZE>");
	runTest<std::forward_list<int> >(push_frontWrapper<std::forward_list<int>, int>, "std::forward_list<int>");
#else
	print::tableHead("C++11 for std::array/std::forward_list");
	std::cout	<< '\n';
#endif

	print::subHeaderLine("Associative Containers");
	runTest<std::set<int> >(insertWrapper<std::set<int>, int>, "std::set<int>");
	runTest<std::multiset<int> >(insertWrapper<std::multiset<int>, int>, "std::multiset<int>");
	std::cout	<< '\n';

	print::subHeaderLine("Adapter Containers");
	print::note("Protected underlying container");

	return (0);
}

template <typename T, typename FUNC>
void	runTest(FUNC f, std::string name)
{
	print::tableHead(name);
	T	container = createArray<T>(f, EF_SIZE);
	const typename T::value_type	*pos = easyfind(container, EF_SEARCH);
	std::cout	<< std::setw(9)	<< "typeid:"	<< typeid(T).name()	<< '\n'
				<< std::setw(9)	<< "Address:"	<< pos	<< '\n'
				<< std::flush;

	std::string	searchColor(C_RED);
	for (typename T::iterator i = container.begin(); i != container.end(); ++i)
	{
		if (*i == EF_SEARCH)
		{
			if (&(*i) == pos)
			{
				std::cout	<< C_GREEN;
				searchColor = C_LGREEN;
			}
			else
				std::cout	<< searchColor;
		}
		else if (&(*i) == pos)
			std::cout	<< C_RED;
		else
			std::cout	<< C_LCYAN;
		std::cout	<< *i	<< ' ';
	}
	std::cout	<< C_RESET	<< std::endl;
}

template <typename T, typename FUNC>
T	createArray(FUNC f, unsigned int size)
{
	T	container;

	for (unsigned int i = 0; i < size; ++i)
		f(container, std::rand() % EF_MODULO);
	return (container);
}
