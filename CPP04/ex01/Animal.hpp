/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"

# include <iostream>
// std::

class Animal
{
	private:

	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(const Animal &src);
		virtual	~Animal(void);

		virtual void	makeSound(void) const;
		virtual void	displayAddress(void) const;
		std::string		getType(void) const;

		Animal	&operator=(const Animal &src);
};

#endif
