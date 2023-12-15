/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:21:38 by ohengelm          #+#    #+#             */
/*   Updated: 2023/12/14 20:33:40 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "colors.hpp"

#include <iostream>
// std::cout

int	main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		try
		{
			std::cout	<< RPN::calculate(argv[i])	<< std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr	<< C_RED	<< "Error: "
						<< C_RESET	<< e.what()
						<< std::endl;
		}	
	}
	return (0);
}
