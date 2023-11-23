/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 19:21:35 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 19:18:31 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
// std::

class Harl
{
	private:
		std::string	message[4];
		// void		(Harl::*complaint[4])(void);

		size_t	complainIndex(std::string level);

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	grunting(void) const;

	protected:

	public:
		Harl(void);
		Harl(const Harl &src);
		~Harl(void);

		void	complain(std::string level);

		Harl	&operator=(const Harl &src);

};

#endif