/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:37 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/15 16:32:20 by ohengelm         ###   ########.fr       */
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

	void	setRate(const std::string &file);
	double	getRate(const std::string &key);
	std::pair<std::string, double>	convertLine(const std::string &line, char delim);
}

#endif
