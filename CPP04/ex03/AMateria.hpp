/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

// # include "Character.hpp"

# include <iostream>
// std::

class AMateria
{
	private:

	protected:
		std::string const	type;

	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &src);
		virtual ~AMateria(void) = 0;

		std::string	const	&getType(void) const;
		
		virtual void		cast(std::string user, std::string target) = 0;
		virtual AMateria	*clone(void) const = 0;
		// virtual void		use(ICharacter& target);

		AMateria	&operator=(const AMateria &src);
};

#endif
