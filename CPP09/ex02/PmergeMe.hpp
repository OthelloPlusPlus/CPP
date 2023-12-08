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

class PmergeMe
{
	private:

	protected:

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &src);
		~PmergeMe(void);

		PmergeMe	&operator=(const PmergeMe &src);
};

#endif
