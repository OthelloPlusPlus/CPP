/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:17:30 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/08 17:41:41 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename CONT, typename VAR>
void	push_backWrapper(CONT &container, VAR arg)
{
	container.push_back(arg);
}

template <typename CONT, typename VAR>
void	push_frontWrapper(CONT &container, VAR arg)
{
	container.push_front(arg);
}

template <typename CONT, typename VAR>
void	insertWrapper(CONT &container, VAR arg)
{
	container.insert(arg);
}
