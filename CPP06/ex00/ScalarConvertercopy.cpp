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

#include "ScalarConvertercopy.hpp"

#include <ios>
// std::scientific
// std::fixed
#include <iostream>
// std::cout
#include <exception>
// std::exception
#include <iomanip>
// std::setprecision

ScalarConverter::ScalarConverter(char *value): value(value)
{
	if (this->value.length() == 1 && std::isprint(this->value[0]) && !std::isdigit(this->value[0])) 
		this->value = std::to_string(this->value[0]);
}

void	ScalarConverter::setPrecision(void)
{
	int	precision(1);

	if (this->value.find_last_of('.') != std::string::npos)
		precision = this->value.length() - this->value.find_last_of('.') - 1;
	if (precision < 0)
		precision = 0;
	if (precision > 10 || this->value.length() > 6)
		std::cout	<< std::scientific;
	else
		std::cout	<< std::fixed	<< std::setprecision(precision);
}

ScalarConverter::operator char()
{
	int		i = static_cast<int>(*this);
	char	c = i % 256;

	if (!std::isprint(c))
			throw(std::range_error("Non displayable"));
	if (i < 0 || i > 255)
		throw (std::out_of_range(c + std::string(" (extended ASCII)")));
	return (c);
}

ScalarConverter::operator int()
{
	int	i;

	try
	{
		i = std::stoi(this->value);
	}
	catch(const std::invalid_argument &e)
	{
		throw (std::invalid_argument("Impossible (invalid argument)"));
	}
	catch(const std::out_of_range &e)
	{
		throw (std::out_of_range("Impossible (out of range)"));
	}
	catch(const std::exception& e)
	{
		throw (std::runtime_error(typeid(e).name()));
	}
	return (i);
}

ScalarConverter::operator float()
{
	float f;

	try
	{
		f = std::stof(this->value);
	}
	catch(const std::invalid_argument &e)
	{
		throw (std::invalid_argument("Impossible (invalid argument)"));
	}
	catch(const std::out_of_range &e)
	{
		throw (std::out_of_range("Impossible (out of range)"));
	}
	catch(const std::exception& e)
	{
		throw (std::runtime_error(typeid(e).name()));
	}
	return (f);
}

ScalarConverter::operator double()
{
	double d;

	try
	{
		d = std::stod(this->value);
	}
	catch(const std::invalid_argument &e)
	{
		throw (std::invalid_argument("Impossible (invalid argument)"));
	}
	catch(const std::out_of_range &e)
	{
		throw (std::out_of_range("Impossible (out of range)"));
	}
	catch(const std::exception& e)
	{
		throw (std::runtime_error(typeid(e).name()));
	}
	return (d);
}
