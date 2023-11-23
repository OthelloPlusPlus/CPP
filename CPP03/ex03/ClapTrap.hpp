/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
// std::

#define PRINT_INFO	std::setw(9)	<< std::left
#define PRINT_RESET	C_RESET	<< std::right

class ClapTrap
{
	private:
		std::string			type;
		std::string const	name;
		unsigned int		HPMax;
		unsigned int		HPCurrent;
		unsigned int		EPMax;
		unsigned int		EPCurrent;
		unsigned int		AttackDamage;

	protected:
		static const unsigned int	defaultHP = 10;
		static const unsigned int	defaultEP = 10;
		static const unsigned int	defaultAD = 0;

	public:
		ClapTrap(std::string const new_name);
		ClapTrap(std::string const new_name, const unsigned new_HP, const unsigned new_EP, const unsigned new_AD);
		ClapTrap(const ClapTrap &src);
		~ClapTrap(void);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void			displayClassName(std::string col1, std::string col2) const;
		virtual void	displaySelf(void) const;
		virtual void	displayInfo(void) const;

		const std::string	getType(void) const;
		void				setType(const std::string new_type);
		const std::string	getName(void) const;
		unsigned int		getHPMax(void) const;
		void				setHPMax(const unsigned int value);
		unsigned int		getHPCurrent(void) const;
		void				setHPCurrent(const unsigned int value);
		unsigned int		getEPMax(void) const;
		void				setEPMax(const unsigned int value);
		unsigned int		getEPCurrent(void) const;
		void				setEPCurrent(const unsigned int value);
		unsigned int		getAttackDamage(void) const;
		void				setAttackDamage(const unsigned int value);

		ClapTrap	&operator=(const ClapTrap &src);
};

#endif
