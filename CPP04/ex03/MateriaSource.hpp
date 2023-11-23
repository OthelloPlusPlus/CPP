/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/05/06 13:31:37 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MateriaSource_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		int			size;
		AMateria	*(known[4]);

	protected:

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		~MateriaSource(void);

		void		learnMateria(AMateria *type);
		AMateria	*createMateria(std::string const &type);
		void		displayMateria(std::string const &type) const;

		MateriaSource	&operator=(const MateriaSource &src);
};

#endif
