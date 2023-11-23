/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 16:15:23 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/05/03 18:38:20 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "print.hpp"
#include "colors.hpp"

#include <iostream>
// std::

void	ex02Custom(void);
void	seeNSay(const Animal *seen);

int main()
{
	srand(time(NULL));
	ex02Custom();
}


void	ex02Custom(void)
{
	print::headerLine("Abstract class - custom");

	print::subHeaderLine("Functinal Code");
	{
		Cat	cat;
		Animal	*pointerDog = new Dog();

		delete pointerDog;
	}
	print::subHeaderLine("Instantiating abstract class");
	// Animal	abstract;
}
