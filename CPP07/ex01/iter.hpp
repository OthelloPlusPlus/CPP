/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:36:07 by ohengelm          #+#    #+#             */
/*   Updated: 2023/11/30 20:37:36 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include "colors.hpp"

#include <iostream>
// std::cout
#include <iomanip>
// std::setw

template <typename PTR, typename INDEX, typename FUNC>
void	iter(PTR *ptr, INDEX len, FUNC f)
{
	if (ptr == NULL || f == NULL)
		return ;
	for (INDEX i = 0; i < len; ++i)
		f(ptr[i]);
}

#endif
