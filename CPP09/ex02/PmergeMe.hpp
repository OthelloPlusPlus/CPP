/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 19:20:43 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/08 19:20:43 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
//std::ostream

template <typename CONTAINER>
class PmergeMe
{
	private:
		CONTAINER	container;
		CONTAINER	low;

		int		convertToInt(const char *arg) const;
		int		extractDangler(void);
		void	splitContainer(void);
		void	largestOnTop(void);
		void	sortHighAscending(void);
		void	priorityInsert(void);

		void	printContents(void);

	protected:

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &src);
		~PmergeMe(void);

		void	sort(int argc, char **argv);
		void	parseInput(int argc, char **argv);

		const CONTAINER &getContainer(void) const {return (this->container);}

		PmergeMe	&operator=(const PmergeMe &src);
};

template <typename CONTAINER>
std::ostream	&operator<<(std::ostream &out, PmergeMe<CONTAINER> &src);

#include "PmergeMe.tpp"

#endif
