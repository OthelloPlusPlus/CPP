/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:36:07 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/01 17:34:33 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
// NULL

template <typename PTR, typename INDEX, typename FUNC>
void	iter(PTR *ptr, INDEX len, FUNC f)
{
	if (ptr == NULL || f == NULL)
		return ;
	for (INDEX i = 0; i < len; ++i)
		f(ptr[i]);
}

template <typename PTR, typename INDEX, typename FUNC>
void	iter(PTR *dst, PTR *src, INDEX len, FUNC f)
{
	if (dst == NULL || src == NULL || f == NULL)
		return ;
	for (INDEX i = 0; i < len; ++i)
		dst[i] = f(src[i]);
}

#endif
