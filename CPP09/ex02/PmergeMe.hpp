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

#include <vector>
// std::vector
#include <deque>
// std::deque
#include <list>
// std::list

#include <iostream>
//std::ostream

class PmergeMe
{
	private:
		std::vector<size_t>	vector;
		std::deque<size_t>		deque;
		std::list<size_t>		list;

		template <typename CONTAINER>
			CONTAINER	&merge(CONTAINER &first, CONTAINER &second);
		std::vector<size_t>	&retrieveContainer(std::vector<size_t>) {return (this->vector);}
		std::deque<size_t>		&retrieveContainer(std::deque<size_t>) {return (this->deque);}
		std::list<size_t>		&retrieveContainer(std::list<size_t>) {return (this->list);}

	protected:

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &src);
		~PmergeMe(void);

		template <typename CONTAINER>
			void	sort(void);
		const std::vector<size_t>	&getList(std::vector<size_t>) const {return (this->vector);}
		const std::deque<size_t>	&getList(std::deque<size_t>) const {return (this->deque);}
		const std::list<size_t>	&getList(std::list<size_t>) const {return (this->list);}
		template <typename CONTAINER>
			std::ostream	&printRandom(std::ostream &out, const CONTAINER &container);

		PmergeMe	&operator=(const PmergeMe &src);
};

std::ostream	&operator<<(std::ostream &out, PmergeMe &src);

#endif
