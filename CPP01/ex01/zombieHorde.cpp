/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 15:22:37 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/23 20:06:09 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// #include <iostream>
#include <iostream>
// std::

static std::string	st_random_name(void);

Zombie	*zombieHorde(int N, std::string new_name)
{
	Zombie	*horde;
	int		i;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];
	
	i = 0;
	while (i < N)
	{
		horde[i].setName(new_name + " " + std::to_string(i) + " " + st_random_name());
		i++;
	}
	return (horde);
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
