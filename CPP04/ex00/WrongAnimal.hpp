/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
// std::

class WrongAnimal
{
	private:

	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal(void);

		void	makeSound(void) const;
		std::string		getType(void) const;

		WrongAnimal	&operator=(const WrongAnimal &src);
};

#endif
