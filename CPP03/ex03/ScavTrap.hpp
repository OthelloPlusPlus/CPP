/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/04/22 16:17:22 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>
// std::

class ScavTrap: virtual public ClapTrap
{
	private:
		int	mode;

	protected:
		static const unsigned int	defaultHP = 100;
		static const unsigned int	defaultEP = 50;
		static const unsigned int	defaultAD = 20;

	public:
		ScavTrap(std::string new_name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap(void);
		
		void	attack(const std::string &target);
		void	guardGate(void);
		virtual void	displaySelf(void) const;
		virtual void	displayInfo(void) const;

		ScavTrap	&operator=(const ScavTrap &src);
};

#endif
