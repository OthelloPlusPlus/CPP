/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 16:36:59 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 19:15:48 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

# include <iostream>
// std::

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	protected:

	public:
		HumanB(const std::string new_name);
		HumanB(const HumanB &src);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon &new_weapon);

		HumanB	&operator=(const HumanB &src);

};

#endif