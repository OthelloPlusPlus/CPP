/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# include <iostream>
// std::

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	name;

	protected:
		using FragTrap::defaultHP;
		using ScavTrap::defaultEP;
		using FragTrap::defaultAD;

	public:
		DiamondTrap(std::string new_name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap(void);

		void	whoAmI(void);

		virtual void	displaySelf(void) const;
		virtual void	displayInfo(void) const;
		void	displayDiamondInfo(void) const;
		using ScavTrap::attack;

		DiamondTrap	&operator=(const DiamondTrap &src);
};

#endif
