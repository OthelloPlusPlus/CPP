/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: virtual public Animal
{
	private:
		Brain		*brain;

	protected:

	public:
		Cat(void);
		Cat(const Cat &src);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;
		void			displayAddress(void) const;

		Cat	&operator=(const Cat &src);
};

#endif
