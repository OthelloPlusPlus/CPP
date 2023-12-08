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
		//stl_list.h
		typedef std::reverse_iterator<iterator> 		reverse_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

		iterator			begin(void)		{if (this->c.size() == 0) return (this->end()); return (&this->c.front());};
		reverse_iterator	rbegin(void)	{if (this->c.size() == 0) return (this->rend()); return reverse_iterator(&this->c.back() + 1);};
		iterator			back(void)		{return (&this->c.back());};	
		iterator			end(void)		{return (&this->c.back() + 1);};
		reverse_iterator	rend(void)		{return reverse_iterator(&this->c.front());};
		const_iterator			begin(void) const	{if (this->c.size() == 0) return (this->end()); return (&this->c.front());};
		const_reverse_iterator	rbegin(void) const	{if (this->c.size() == 0) return (this->rend()); return const_reverse_iterator(&this->c.back() + 1);};
		const_iterator			back(void) const	{return (&this->c.back());};	
		const_iterator			end(void) const		{return (&this->c.back() + 1);};
		const_reverse_iterator	rend(void) const	{return const_reverse_iterator(&this->c.front());};

		T	&operator[](unsigned int i) {return (this->c[i]);};
		const T	&operator[](unsigned int i) const {return (this->c[i]);};
};

#endif
