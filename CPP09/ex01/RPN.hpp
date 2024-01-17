/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 19:20:17 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/08 19:20:17 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
// std::string

namespace RPN
{
	/**
	 * @name	RPN
	 * @file	RPN.cpp
	 * @author	Othello
	 * 
	 * @brief
	 * Passes through the passed values and calculates them using them Postfix/Reverse Polish.
	 * 
	 * @param input String containing the equasion to be solved.
	 * @note ' ' is used as deliminator in the string.
	 * @return	The calculated value.
	*/
	double	calculate(std::string input);
} // namespace RPN

#endif
