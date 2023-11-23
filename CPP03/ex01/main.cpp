/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 16:17:40 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/04/22 16:10:40 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <iomanip>
// std::setw()

void	ex00(void);
void	ex01(void);

int	main(void)
{
	// ex00();
	ex01();
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

void	ex01(void)
{
	print::headerLine("Exercise 01: Serena, my love!");

	ScavTrap	witcher("Gerald");

	{
		print::subHeaderLine("Round 0");
		ClapTrap	nekker("Nekker");
		ClapTrap	ghoul("Ghoul");
		witcher.guardGate();

		print::subHeaderLine("Round 1");
		nekker.attack(witcher.getName());
		witcher.takeDamage(nekker.getAttackDamage());
		ghoul.attack(witcher.getName());
		witcher.takeDamage(ghoul.getAttackDamage());
		witcher.attack(nekker.getName());
		nekker.takeDamage(witcher.getAttackDamage());

		print::subHeaderLine("Round 2");
		nekker.attack(witcher.getName());
		ghoul.attack(witcher.getName());
		witcher.takeDamage(ghoul.getAttackDamage());
		witcher.attack(ghoul.getName());
		ghoul.takeDamage(witcher.getAttackDamage());
		ghoul.attack(witcher.getName());
		witcher.guardGate();
	}

	print::subHeaderLine("Display stats");
	witcher.displayInfo();
	std::cout	<< std::endl;
}
