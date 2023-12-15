/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 19:20:17 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/08 19:20:17 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stack>
// std::stack
#include <cmath>
// std::floor()
// std::pow()
#include <stdexcept>
// std::exception
#include <string>
// std::string

namespace
{

	void executeOperation(std::stack<double> &value, std::string &operation)
	{
		if (value.size() < 2)
			throw (std::underflow_error("Not enough numeric arguments"));
		double	carry = value.top();
		value.pop();
		switch (operation[0])
		{
			case '+':	value.top() += carry;	break ;
			case '-':	value.top() -= carry;	break ;
			case '/':	value.top() /= carry;	break ;
			case '*':	value.top() *= carry;	break ;
			case '%':	value.top() /= carry;
						value.top() = (value.top() - std::floor(value.top())) * carry;
						break ;
			case '^':	value.top() = std::pow(value.top(), carry);	break ;
			default:	throw(std::invalid_argument("Invalid operator: " + operation));
		}
	}

	double	stodWrapper(std::string &current)
	{
#if __cplusplus >= 201103L
		return (std::stod(current));
#else
		double 	value(0);
		double	decimal(0);

		size_t	period = current.find_first_of('.');
		if (current.find_first_not_of("1234567890.") != std::string::npos ||\
			current.find_first_not_of("1234567890", period + 1) != std::string::npos)
			throw (std::invalid_argument("Invalid argument: " + current));

		if (period != std::string::npos)
			for (size_t i = current.size() - 1; i > period; --i)
			{
				decimal += current[i] - '0';
				decimal /= 10;
			}
		else
			period = current.size();
		for (size_t i = 0; i < period; ++i)
		{
			value *= 10;
			value += current[i] - '0';
		}
		return (value + decimal);
#endif
	}
}

double	RPN::calculate(std::string input)
{
	std::stack<double>	value;

	if (input.empty())
		return (0);
	while (!input.empty())
	{
		size_t		start = input.find_first_not_of(' ');
		size_t		end = input.find_first_of(' ', start);
		if (start == std::string::npos)
			break ;
		std::string	current = input.substr(start, end - start);

		if (current.find_first_not_of("1234567890.") == std::string::npos)
			value.push(::stodWrapper(current));
		else if (current.size() == 1)
			::executeOperation(value, current);
		else
			throw (std::invalid_argument("Invalid argument: " + current));

		input.erase(start, end - start + 1);
		if (end == std::string::npos)
			break ;
	}
	if (value.size() != 1)
		throw (std::overflow_error("Too many numeric arguments"));
	return (value.top());
}
