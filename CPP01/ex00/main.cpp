/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 14:50:23 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 17:00:22 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <iomanip>
// setw()
#include <stdlib.h> 
// rand
#include <time.h>
// time

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

static void 		st_print_info_line(std::string string);
static std::string	st_random_name(void);

int	main(void)
{
	srand(time(NULL));

	st_print_info_line("Making stack zombie horde");
	Zombie	stack_zombie0(st_random_name());
	stack_zombie0.announce();
	Zombie	stack_zombie1(st_random_name());
	stack_zombie1.announce();
	Zombie	stack_zombie2(st_random_name());
	stack_zombie2.announce();

	st_print_info_line("Making zombies randomly wandering");
	randomChump(st_random_name());
	randomChump(st_random_name());
	randomChump(st_random_name());

	st_print_info_line("Preparing the heap zombie horde");
	Zombie	*heap_zombie0;
	Zombie	*heap_zombie1;
	Zombie	*heap_zombie2;

	st_print_info_line("Making heap zombie horde");
	heap_zombie0 = newZombie(st_random_name());
	heap_zombie0->announce();
	heap_zombie1 = newZombie(st_random_name());
	heap_zombie1->announce();
	heap_zombie2 = newZombie(st_random_name());
	heap_zombie2->announce();

	st_print_info_line("Destroying the heap zombie horde");
	delete heap_zombie0;
	delete heap_zombie1;
	delete heap_zombie2;

	st_print_info_line("Exiting main, thereby destroying stack zombies");

	return (0);
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

/* Michael Jackson's Thriller

	Reed Armstrong
	Rick Baker
	Kim Blank
	Kevin Brennan
	James Canino
	Greg Cannom
	Casey Cole
	John Command
	Michelle Defevre
	Michael DeLorenzo
	Tony Fields

https://www.imdb.com/title/tt0088263/
*/
static std::string	st_random_name(void)
{
	std::string name[] = {
	"Michael Jackson",
	"Reed",
	"Rick",
	"Kim",
	"Kevin",
	"James",
	"Greg",
	"Casey",
	"John",
	"Michelle",
	"Michael",
	"Tony"
	};
	return (name[(rand() % sizeof(name) / sizeof(std::string))]);
}
