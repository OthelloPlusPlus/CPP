/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:52:47 by ohengelm          #+#    #+#             */
/*   Updated: 2023/11/30 17:30:08 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &val1, T &val2)
{
	T	temp = val1;

	val1 = val2;
	val2 = temp;
}

template <typename T>
T min(T val1)
{
	return (val1);
}

template <typename T>
T max(T val1)
{
	return (val1);
}

template <typename T>
T	min(T &val1, T &val2)
{
	if (val1 <= val2)
		return (val1);
	return (val2);
}

template <typename T>
T	max(T &val1, T &val2)
{
	if (val1 >= val2)
		return (val1);
	return (val2);
}

# if __cplusplus >= 201103L
template <typename T, typename... Args>
T min(T val1, Args... args)
{
	T	val2 = min(args...);
	if (val1 <= val2)
		return (val1);
	return (val2);
}

template <typename T, typename... Args>
T max(T val1, Args... args)
{
	T	val2 = min(args...);
	if (val1 >= val2)
		return (val1);
	return (val2);
}
# endif

#endif
