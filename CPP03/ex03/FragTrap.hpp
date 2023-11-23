/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/04/22 16:17:05 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>
// std::

class FragTrap: virtual public ClapTrap
{
	private:
		bool	excited;

	protected:
		static const unsigned int	defaultHP = 100;
		static const unsigned int	defaultEP = 100;
		static const unsigned int	defaultAD = 30;

	public:
		FragTrap(std::string new_name);
		FragTrap(const FragTrap &src);
		~FragTrap(void);
		
		void	highFivesGuys(void);
		virtual void	displaySelf(void) const;
		virtual void	displayInfo(void) const;

		FragTrap	&operator=(const FragTrap &src);
};

#endif
