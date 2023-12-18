/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:37 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/18 12:42:54 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <fstream>
// std::ifstream
#include <iomanip>
// std::setprecision()
#include <cmath>
// std::pow()

/** ************************************************************************ **\
 * 
 * 	Initializer
 * 
\* ************************************************************************** */

struct BitcoinExchangeInit
{
	BitcoinExchangeInit(void)
	{
		try
		{
			BitcoinExchange::setRate("file/data.csv");
		}
		catch(const std::exception &e)
		{
			std::cerr	<< C_RED	<< "Errors: "
						<< C_RESET	<< e.what()
						<< std::endl;
			exit(1);
		}
	}
};

static BitcoinExchangeInit	init;

/** ************************************************************************ **\
 * 
 * 	Anonymous Namespace
 * 
\* ************************************************************************** */

namespace
{
	double	stringToNum(const std::string &string)
	{
		double	value(0);

		size_t i = 0;
		if (string[0] == '-' || string[0] == '+')
			++i;
		for (size_t period = 0; i < string.size(); ++i)
		{
			if (string[i] >= '0' && string[i] <= '9')
			{
				if (!period)
					value = value * 10 + string[i] - '0';
				else
				{
					value = value + (string[i] - '0') / std::pow(10, period);
					++period;
				}
			}
			else if (!period && string[i] == '.')
				period = 1;
			else
				throw(std::invalid_argument("Bad rate => " + string));
		}
		if (string[0] == '-')
			value = -value;
		return (value);
	}

	void	validateDate(const std::string &date)
	{
		std::string	low("0000-00-00");
		std::string	high("9999-19-39");

		if (date.size() != low.size())
			throw(std::invalid_argument("Bad date size => " + date));
		for (size_t	i = 0; i < date.size(); ++i)
			if (date[i] < low[i] || date[i] > high[i])
				throw(std::invalid_argument("Bad date => " + date));
	}
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

double	BitcoinExchange::getRate(const std::string &key)
{
	::validateDate(key);
	std::map<std::string, double>::iterator pos = BitcoinExchange::rate.upper_bound(key);

	if (pos == BitcoinExchange::rate.begin())
		throw (std::range_error("Date before Bitcoin existed."));
	--pos;
	return (pos->second);
}

void	BitcoinExchange::setRate(const std::string &file)
{
	std::ifstream	fileFD;
	std::string		line;

	fileFD.open(file.c_str());
	if (!fileFD)
		throw (std::runtime_error("Failed to open " + file));
	while (std::getline(fileFD, line))
	{
		try
		{
			if (line.empty() || line[0] == '#' || line == "date,exchange_rate")
				continue ;
			std::pair<std::string, double>	parsed = BitcoinExchange::convertLine(line, ',');
			BitcoinExchange::rate[parsed.first] = parsed.second;
		}
		catch(const std::exception &e)
		{
			std::cerr	<< C_RED	<< "Error: "
						<< C_RESET	<< e.what()
						<< std::endl;
		}
	}
	fileFD.close();
}

std::pair<std::string, double>	BitcoinExchange::convertLine(const std::string &line, char delim)
{
	std::string	key(line);
	for (std::string::iterator i = key.begin(); i != key.end(); ++i)
		if (std::isspace(*i))
			key.erase(i--);
	std::size_t	pos = key.find_first_of(delim);
	if (pos == std::string::npos || pos == key.size() - 1 ||\
		pos != key.find_last_of(delim))
		throw (std::invalid_argument("Bad input => " + line));
	double	value = ::stringToNum(key.substr(pos + 1));
	key = key.substr(0, pos);
	::validateDate(key);
	return (std::pair<std::string, double>(key, value));
}
