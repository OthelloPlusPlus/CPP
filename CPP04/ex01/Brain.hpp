/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
// std::

class Brain
{
	private:
		std::string	ideas[100];

		void	addIdeas(int amount);

	protected:

	public:
		Brain(void);
		Brain(const Brain &src);
		~Brain(void);

		std::string	getRandomThought(void) const;

		Brain	&operator=(const Brain &src);
};

#endif
