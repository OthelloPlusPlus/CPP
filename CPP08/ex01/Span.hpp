/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 15:56:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/07 15:56:13 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
// std::vector

class Span
{
	private:
		unsigned int	maxSize;
		std::vector<int>	span;

	protected:

	public:
		Span(unsigned int size);
		Span(const Span &src);
		~Span(void);

		void	addNumber(int value);
		void	addNumbers(unsigned int count);
		long	shortestSpan(void) const;
		long	longestSpan(void) const;

		unsigned int	size(void) const {return (this->span.size());};
		unsigned int	maxsize(void) const {return (this->maxSize);};
		void	printSpan(void);


		Span	&operator=(const Span &src);
};

#endif
