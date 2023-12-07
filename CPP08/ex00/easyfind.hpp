/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:31:27 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/07 14:49:39 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
// std::find

template <typename T>
const typename T::value_type	*easyfind(T &container, int needle)
{
	const typename T::iterator	pos = std::find(container.begin(), container.end(), needle);

	if (pos == container.end())
		return (NULL);
	return (&(*pos));
}

#endif
