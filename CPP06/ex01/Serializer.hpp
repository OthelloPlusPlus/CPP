/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);

	protected:

	public:
		// Serializer(void);
		// Serializer(const Serializer &src);
		// ~Serializer(void);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

		// Serializer	&operator=(const Serializer &src);
};

#endif
