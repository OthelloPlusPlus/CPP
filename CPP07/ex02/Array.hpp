/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 15:42:35 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/11/29 15:42:35 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#define ARRAY_TEMPLATE template <typename T>

ARRAY_TEMPLATE
class Array
{
	private:
		unsigned int	n;
		T				*value;

	protected:

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &src);
		~Array(void);

		unsigned int	size(void) const;

		Array	&operator=(const Array &src);
		T		&operator[](unsigned int i) const;
};

# include "Array.tpp"

#endif
