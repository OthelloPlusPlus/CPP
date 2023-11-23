/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 16:36:59 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/10 18:01:56 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	type;

	protected:

	public:
		Weapon(const std::string new_type);
		Weapon(const Weapon &src);
		~Weapon(void);

		const std::string	&getType(void);
		void				setType(std::string new_type);

		Weapon	&operator=(const Weapon &src);

};

#endif