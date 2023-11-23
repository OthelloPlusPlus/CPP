/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
// # include "Character.hpp"

# include <iostream>
// std::

class Cure: virtual public AMateria
{
	private:

	protected:

	public:
		Cure(void);
		Cure(const Cure &src);
		~Cure(void);

		void		cast(std::string user, std::string target);
		AMateria	*clone(void) const;

		Cure	&operator=(const Cure &src);
};

#endif
