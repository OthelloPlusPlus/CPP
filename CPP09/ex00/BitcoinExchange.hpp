/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:37 by ohengelm          #+#    #+#             */
/*   Updated: 2024/01/17 18:45:25 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
// std::map
#include <string>
// std::string

namespace BitcoinExchange
{
	static std::map<std::string, double>	rate;

	/**
	 * @name	BitCoinExchange
	 * @file	BitCoinExchange.cpp
	 * @author	Othello
	 * 
	 * @brief
	 * Reads the passed files for BitCoin values.
	 * Stores values in an std::map<>.
	 * 
	 * @param file Name of the file to be read.
	 * @note Expected syntax in the file is yyyy-mm-dd,value
	*/
	void	setRate(const std::string &file);

	/**
	 * @name	BitCoinExchange
	 * @file	BitCoinExchange.cpp
	 * @author	Othello
	 * 
	 * @brief
	 * Finds the Bitcoins value on a passed date.
	 * 
	 * @param	date	date
	 * @return	Bitcoin value
	*/
	double	getRate(const std::string &key);


	/**
	 * @name	BitCoinExchange
	 * @file	BitCoinExchange.cpp
	 * @author	Othello
	 * 
	 * @brief
	 * Takes a line yyyy-mm-dd[delim]value. Splits it in to date and value.
	 * 
	 * @param	date	date
	 * @return	An std::pair<> containing a date and a value
	*/
	std::pair<std::string, double>	convertLine(const std::string &line, char delim);
}

#endif
