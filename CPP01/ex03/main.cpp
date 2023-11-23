/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 19:09:19 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 19:12:23 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <iomanip>
// std::setw()

static void	st_print_info_line(std::string string);

int main()
{
	st_print_info_line("Testing Human A with a reference to Weapon");
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	st_print_info_line("Testing Human B with a pointer to Weapon");
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

static void	st_print_info_line(std::string string)
{
	string.insert(0, " ");
	std::cout	<< "\n"
				<< CB_ORANGE << C_BOLD << C_SILVER\
				<< std::setw(80) << std::left << string\
				<< C_RESET\
				<< std::endl;
}
