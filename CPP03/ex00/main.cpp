/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 16:17:40 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/04/22 16:12:07 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <iomanip>
// std::setw()

void	ex00(void);

int	main(void)
{
	ex00();
}

void	ex00(void)
{
	print::headerLine("Exercise 00: Aaaaand... OPEN!");

	ClapTrap	goblin("Goblin");
	ClapTrap	skeleton("Skeleton");
	int			i;

	std::cout	<< std::endl;
	i = 0;
	while (i < 3)
	{
		goblin.attack("Skeleton");
		skeleton.takeDamage(1);
		skeleton.beRepaired(10);
		i++;
	}

	std::cout	<< std::endl;
	i = 0;
	while (i < 7)
	{
		goblin.attack("Skeleton");
		i++;
	}
	goblin.attack("Skeleton");
	skeleton.takeDamage(i);

	std::cout	<< std::endl;
	goblin.beRepaired(10);
	skeleton.attack("Goblin");
	goblin.takeDamage(99);
	goblin.attack("Skeleton");
	skeleton.beRepaired(10);

	std::cout	<< std::endl;
}
