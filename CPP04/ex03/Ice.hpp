/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
// # include "Character.hpp"

# include <iostream>
// std::

class Ice: virtual public AMateria
{
	private:

	protected:

	public:
		Ice(void);
		Ice(const Ice &src);
		~Ice(void);

		void		cast(std::string user, std::string target);
		AMateria	*clone(void) const;

		Ice	&operator=(const Ice &src);
};

#endif
