/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:36:07 by ohengelm          #+#    #+#             */
/*   Updated: 2023/11/24 20:36:08 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"

#include <iostream>
// std::cout
#include <iomanip>
// std::setw

template <typename PTR, typename INDEX, typename FUNC>
void	iter(PTR &ptr, INDEX len, FUNC f)
{ 
	for (INDEX i = 0; i < len; ++i)
		ptr[i] = f(ptr[i]);
}

template <typename PTR, typename INDEX, typename FUNC>
void	testIter(PTR ptr, INDEX len, FUNC f)
{
	std::cout	<< C_RESET	<< '\n'
				<< std::setw(11)	<< "Original:"	<< '[';
	for (INDEX i = 0; i < len; ++i)
		std::cout	<< ptr[i];
	std::cout	<< ']'	<< std::endl;
	::iter(ptr, len, f);
	std::cout	<< std::setw(11)	<< "Iteratred:"	<< '[';
	for (INDEX i = 0; i < len; ++i)
		std::cout	<< ptr[i];
	std::cout	<< ']'	<< std::endl;
}
