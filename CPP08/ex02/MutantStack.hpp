/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 20:27:59 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/07 20:27:59 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
// std::stack

template <typename T>
class MutantStack: public std::stack<T>
{
	private:

	protected:

	public:
		typedef T		*iterator;
		typedef const T	*const_iterator;

		iterator	begin(void) {return &this->c.front();};
		iterator	back(void) {return (&this->c.back());};	
		iterator	end(void) {return (&this->c.back() + 1);};
		const_iterator	begin(void) const {return &this->c.front();};
		const_iterator	back(void) const {return (&this->c.back());};	
		const_iterator	end(void) const {return (&this->c.back() + 1);};

		T	&operator[](unsigned int i) {return (this->c[i]);};
		const T	&operator[](unsigned int i) const {return (this->c[i]);};
};

#endif
