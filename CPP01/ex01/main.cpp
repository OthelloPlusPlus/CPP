/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 14:50:23 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/23 19:51:08 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <iomanip>
// std::setw()
#include <stdlib.h> 
// rand
#include <time.h>
// time

Zombie	*zombieHorde(int N, std::string name);

static void			st_test_horde(int N, std::string undead);
static void 		st_print_info_line(std::string string);
static void			st_print_subinfo_line(std::string string);

int	main(void)
{
	srand(time(NULL));

	st_test_horde(-1, "Ghost");
	st_test_horde(0, "Wight");
	st_test_horde(1, "Mummy");
	st_test_horde(2, "Ghoul");
	st_test_horde(23, "Zombie");

	return (0);
}

static void	st_test_horde(int N, std::string undead)
{
	Zombie	*horde;
	int		i;

	st_print_info_line("Making a horde of " + std::to_string(N) + " " + undead);
	st_print_subinfo_line("Raising the horde from the grave");
	horde = zombieHorde(N, undead);
	st_print_subinfo_line("Making the horde announce itself");
	i = 0;
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	st_print_subinfo_line("Destroying the horde");
	delete [] horde;
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

static void	st_print_subinfo_line(std::string string)
{
	string.insert(0, " ");
	std::cout	<< "\n"
				<< CB_DORANGE << C_BOLD << C_SILVER\
				<< std::setw(42) << std::left << string\
				<< C_RESET\
				<< std::endl;
}
