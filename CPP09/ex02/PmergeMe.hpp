/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:19:18 by ohengelm          #+#    #+#             */
/*   Updated: 2024/01/17 18:19:20 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
//std::vector
# include <list>
//std::list
# include <deque>
//std::deque

#include "size_c.hpp"

namespace PmergeMe
{
/**
 * @name	PmergeMe
 * @file	PmergeMe.tpp
 * @author	Othello
 * 
 * @brief
 * Converts argv in to size_t values. 
 * Stores the values into specified container.
 * Sorts the values stored in the container.
 * @tparam CONTAINER Type of container (vector, list or deque)
 * @param argc 
 * @param argv Sequence of positive integers
 * @return Container containing the sequence
 */
	template <template <typename...> class CONTAINER>
	CONTAINER<size_c>	sort(int argc, char **argv);
	
/**
 * @name	PmergeMe
 * @file	PmergeMe.tpp
 * @author	Othello
 * 
 * @brief
 * Sorts the values stored in the container.
 * @tparam container Sequence of positive integers
 * @return Container containing the sequence
 */
	template <template <typename...> class CONTAINER>
	CONTAINER<size_c>	sort(CONTAINER<size_c> container);

/**
 * @name	PmergeMe
 * @file	PmergeMe.tpp
 * @author	Othello
 * 
 * @brief
 * Converts argv in to size_t values. 
 * Stores the values into specified container.
 * @tparam CONTAINER Type of container (vector, list or deque)
 * @param argc 
 * @param argv Sequence of positive integers
 * @return Container containing the sequence
 */
	template <template <typename...> class CONTAINER>
	CONTAINER<size_c>	unsorted(int argc, char **argv);

/**
 * @name	PmergeMe
 * @file	PmergeMe.tpp
 * @author	Othello
 * 
 * @brief
 * Prints up to 8 integers in the container.
 * @tparam	container Container containing sequence of integers
 */
	template <typename CONTAINER>
	void	print(CONTAINER &container);
}

#include "PmergeMe.tpp"

#endif
