/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 16:36:59 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 19:04:32 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

# include <iostream>

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;

	protected:

	public:
		HumanA(const std::string new_name, Weapon &new_weapon);
		HumanA(const HumanA &src);
		~HumanA(void);

		void	attack(void);

		HumanA	&operator=(const HumanA &src);

};

#endif