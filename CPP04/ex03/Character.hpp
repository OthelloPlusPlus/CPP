/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/05/06 13:45:05 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# include <iostream>
// std::

class Character: public ICharacter
{
	private:
		std::string	name;
		AMateria	*(inventory[4]);
		int			inv_max;

		bool	checkSlot(int idx);

	protected:

	public:
		Character(std::string name);
		Character(const Character &src);
		~Character(void);

		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

		void	displayCharacter(void);

		Character	&operator=(const Character &src);
};

#endif
