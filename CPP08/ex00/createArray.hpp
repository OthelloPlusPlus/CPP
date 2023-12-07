/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createArray.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:38:25 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/07 13:59:47 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATEARRAY_HPP
# define CREATEARRAY_HPP

# define MODULO 42

template <typename T>
T	createArrayPush(unsigned int size)
{
	T	container;

	for (unsigned int i = 0; i < size; ++i)
		container.push(std::rand() % MODULO);
	return (container);
}

template <typename T>
T	createArrayPushBack(unsigned int size)
{
	T	container;

	for (unsigned int i = 0; i < size; ++i)
		container.push_back(std::rand() % MODULO);
	return (container);
}

template <typename T>
T	createArrayPushFront(unsigned int size)
{
	T	container;

	for (unsigned int i = 0; i < size; ++i)
		container.push_front(std::rand() % MODULO);
	return (container);
}

template <typename T>
T	createArrayInsert(unsigned int size)
{
	T	container;

	for (unsigned int i = 0; i < size; ++i)
		container.insert(std::rand() % MODULO);
	return (container);
}

template <typename T>
T	createArraySize(unsigned int size)
{
	T	container;

	for (size_t i = 0; i < container.size(); ++i)
		container[i] = std::rand() % MODULO;
	return (container);
	(void)size;
}

#endif
