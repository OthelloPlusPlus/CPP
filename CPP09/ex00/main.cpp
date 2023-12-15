/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:21:34 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/15 16:03:52 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <iostream>
// std::cout
#include <iomanip>
// std::setw()
#include <fstream>
// std::ifstream
#include <string>
// std::string

static void	openFile(std::ifstream &file, int argc, char **argv);
static bool	getLine(std::ifstream &file, std::string &line);
static void	parseLine(std::string &line, std::string &date, double &stock);

int	main(int argc, char **argv)
{
	std::ifstream	file;
	std::string		line;
	std::string		date;
	double			stock;

	try
	{
		openFile(file, argc, argv);
		while (getLine(file, line))
		{
			try
			{
				parseLine(line, date, stock);
				double	value = stock * BitcoinExchange::getRate(date);
				std::cout	<< std::setw(10)	<< date	<< " => " 
							<< std::setw(7)	<< stock	<< " = "	
							<< value	<< std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr	<< C_RED	<< "Error: "
							<< C_RESET	<< e.what()
							<< std::endl;
			}
		}
	}
	catch(const std::exception &e)
	{
		std::cerr	<< C_RED	<< "Error: "
					<< C_RESET	<< e.what()
					<< std::endl;
	}
	file.close();
	return (errno);
}

static void	openFile(std::ifstream &file, int argc, char **argv)
{
	std::string	intro("Testing file: ");

	if (argc >= 2)
		intro += argv[1];
	print::subHeaderLine(intro);
	if (argc < 2)
		throw(std::invalid_argument("No filename passed."));
	file.open(argv[1]);
	if (!file)
		throw(std::invalid_argument("Could not open file."));
}

static bool	getLine(std::ifstream &file, std::string &line)
{
	while (std::getline(file, line))
	{
		if (line.empty() || line[0] == '#' || line == "date | value")
			continue ;
		return (true);
	}
	return (false);
}

static void	parseLine(std::string &line, std::string &date, double &stock)
{
	std::pair<std::string, double>	pair;
	
	pair = BitcoinExchange::convertLine(line, '|');

	date = pair.first;
	stock = pair.second;
	if (stock < 0)
		throw (std::range_error("Not a positive number."));
	if (stock > 1000)
		throw (std::range_error("Too large number."));
}
