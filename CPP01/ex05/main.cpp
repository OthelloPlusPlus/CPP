/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 19:17:48 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 19:17:50 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "colors.hpp"

int	main(void)
{
	Harl	karen;
	Harl	harl(karen);

	std::cout	<< C_CHRT
				<< std::flush;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::cout	<<	C_ORANGE
				<<	std::flush;
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");

	std::cout	<<	C_RED
				<<	std::flush;
	harl.complain("ERROR I WANT TO SPEAK TO A MANAGER");
	harl.complain("harl is such a karen");
	harl.complain("");

	std::cout	<<	C_RESET
				<<	std::flush;

	return (0);
}
