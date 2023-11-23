/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 14:42:50 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 16:57:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
//std::

class Zombie
{
	private:
		std::string	name;

	protected:

	public:
		Zombie(void);
		Zombie(std::string newname);
		Zombie(const Zombie &src);
		~Zombie(void);

		void	setName(std::string name);
		void	announce(void);
		
		Zombie	&operator=(const Zombie &src);

};

#endif