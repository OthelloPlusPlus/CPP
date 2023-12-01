/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testTemplates.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:23:02 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/01 16:46:58 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"

#include <iostream>
// std::cout
#include <cstdlib>
// std::rand

template <typename T>
void	printArray(T &c)
{
	std::cout	<< c;
}

template <typename T>
void	toUpper(T &c)
{
	c = std::toupper(c);
}

template <typename T>
void	toLower(T &c)
{
	c = std::tolower(c);
}

template <typename T>
void	toLeet(T &c)
{
	c = std::toupper(c);
	switch (static_cast<int>(c))
	{
		case 'O': c = '0'; break;
		case 'I':
		case 'L': c = '1'; break;
		case 'Z': c = '2'; break;
		case 'E': c = '3'; break;
		case 'A': c = '4'; break;
		case 'S': c = '5'; break;
		case 'G': c = '6'; break;
		case 'T': c = '7'; break;
		case 'B': c = '8'; break;
		case 'J': c = '9'; break;
		default:	break;
	}
}

template <typename T>
T	toLeetT(T c)
{
	c = std::toupper(c);
	switch (static_cast<int>(c))
	{
		case 'O': return('0');
		case 'I':
		case 'L': return('1');
		case 'Z': return('2');
		case 'E': return('3');
		case 'A': return('4');
		case 'S': return('5');
		case 'G': return('6');
		case 'T': return('7');
		case 'B': return('8');
		case 'J': return('9');
		default:	return (c);
	}
}

template <typename T>
void	toOdd(T &c)
{
	if (!(static_cast<int>(c) % 2))
		c++;
}
template <typename T>
T	toOddT(T c)
{
	if (!(static_cast<int>(c) % 2))
		c++;
	return (c);
}

template <typename T>
void	(*getRandomVoidFunction())(T &)
{
	switch (rand() % 5)
	{
		case 0: std::cout	<< C_LORANGE	<<	"toUpper";
				return (&toUpper<T>);
		case 1: std::cout	<< C_LORANGE	<<	"toLower";
				return (&toLower<T>);
		case 2: std::cout	<< C_LORANGE	<<	"toLeet";
				return (&toLeet<T>);
		case 3: std::cout	<< C_LORANGE	<<	"toOdd";
				return (&toOdd<T>);
		default:	std::cout	<< C_LORANGE	<<	"NULL";
				return (NULL);
	}
}

template <typename T>
T	(*getRandomTFunction())(T)
{
	switch (rand() % 2)
	{
		case 0: std::cout	<< C_LORANGE	<<	"toUpper";
				return (std::toupper);
		case 1: std::cout	<< C_LORANGE	<<	"toLower";
				return (std::tolower);
		case 2: std::cout	<< C_LORANGE	<<	"toLeet";
				return (&toLeetT<T>);
		case 3: std::cout	<< C_LORANGE	<<	"toOdd";
				return (&toOddT<T>);
		default:	std::cout	<< C_LORANGE	<<	"NULL";
				return (NULL);
	}
}
