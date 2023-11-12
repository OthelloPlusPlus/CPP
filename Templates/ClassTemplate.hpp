/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClassName.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 0000/00/00 00:00:00 by ohengelm      #+#    #+#                 */
/*   Updated: 0000/00/00 00:00:00 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSNAME_HPP
# define CLASSNAME_HPP

class ClassName
{
	private:

	protected:

	public:
		ClassName(void);
		ClassName(const ClassName &src);
		~ClassName(void);

		ClassName	&operator=(const ClassName &src);
};

#endif
