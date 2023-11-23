/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 14:45:33 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/10 15:15:54 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
// std::

void	randomChump(std::string name)
{
	Zombie	zombie(name);

	zombie.announce();
}
