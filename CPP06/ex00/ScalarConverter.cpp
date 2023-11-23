/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <ios>
// std::scientific
// std::fixed
#include <iostream>
// std::cout
#include <iomanip>
// std::setprecision
// std::setw
#include <string>
// std::string
// std::stoi
// std::stof
// std::stod
#include <exception>
// std::exception

#define PRINTW	8

std::string	ScalarConverter::value;

void	ScalarConverter::convert(std::string value)
{
	if (value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0]))
		ScalarConverter::value = std::to_string(value[0]);
	else
		ScalarConverter::value = value;

	ScalarConverter::setCout();
	ScalarConverter::convertTemplate<char>();
	ScalarConverter::convertTemplate<int>();
	ScalarConverter::convertTemplate<float>();
	ScalarConverter::convertTemplate<double>();
	std::cout.copyfmt(std::ios(nullptr));
}

void	ScalarConverter::setCout(void)
{
	int	precision(0);

	if (ScalarConverter::value.find_last_of('.') != std::string::npos)
		precision = ScalarConverter::value.length() - ScalarConverter::value.find_last_of('.') - 1;
	if (precision > 10 || ScalarConverter::value.length() > 6)
		std::cout	<< std::left	<< std::scientific;
	else
		std::cout	<< std::left	<< std::fixed	<< std::setprecision(precision);
}

template <typename T>
void	ScalarConverter::convertTemplate(void)
{
	std::string	name;
	switch (typeid(T).name()[0])
	{
		case 'c':	name = "char";		break;
		case 'i':	name = "int";		break;
		case 'f':	name = "float";		break;
		case 'd':	name = "double";	break;
		default :	name = "unknown";	break;
	}
	std::cout	<< std::setw(PRINTW)	<< name + ':';
	try
	{
		T	type = static_cast<T>(ScalarConverter());
		if (name == "char")
			std::cout	<< '\'';
		std::cout	<< type;
		if (name == "char")
			std::cout	<< '\'';
		else if (name == "float")
			std::cout	<< 'f';
	}
	catch(const std::exception& e)
	{
		std::cout	<< e.what();
	}
	std::cout	<< std::endl;
}

ScalarConverter::operator char()
{
	int		i = static_cast<int>(ScalarConverter());
	char	c = i % 256;

	if (!std::isprint(c))
		throw(std::range_error("Non displayable"));
	if (i < 0 || i > 255)
		throw (std::out_of_range(std::string("'") + c + std::string("' (extended ASCII)")));
	return (c);
}

template <typename T>
ScalarConverter::operator T()
{
	try
	{
		switch (typeid(T).name()[0])
		{
			case 'i':	return (std::stoi(ScalarConverter::value));
			case 'f':	return (std::stof(ScalarConverter::value));
			case 'd':	return (std::stod(ScalarConverter::value));
			default :	throw (std::runtime_error("Unsupported typename"));
		}
	}
	catch(const std::invalid_argument &e)
	{
		throw (std::invalid_argument("Impossible (invalid argument)"));
	}
	catch(const std::out_of_range &e)
	{
		throw (std::out_of_range("Impossible (out of range)"));
	}
	catch(const std::runtime_error &e)
	{
		throw ;
	}
	catch(const std::exception &e)
	{
		throw (std::runtime_error(typeid(e).name()));
	}
}
