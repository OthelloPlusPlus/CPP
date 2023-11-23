/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/05/03 17:09:00 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: virtual public Animal
{
	private:
		Brain		*brain;

	protected:

	public:
		Dog(void);
		Dog(const Dog &src);
		virtual ~Dog(void);

		virtual void makeSound(void) const;

		Dog	&operator=(const Dog &src);
};

#endif
