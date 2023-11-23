/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 16:15:23 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/05/06 15:37:39 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "print.hpp"
#include "colors.hpp"

#include <iostream>
// std::

int		ex01Subject(void);
void	ex01Custom(void);
void	seeNSay(const Animal *seen);

int main()
{
	srand(time(NULL));
	ex01Subject();
	ex01Custom();
}

int	ex01Subject(void)
{
	print::headerLine("Exercise 01: I don’t want to set the world on fire");
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
// ...
return 0;
}

void	ex01Custom(void)
{
	print::headerLine("Exercise 01: I don’t want to set the world on fire - custom");
	Animal	*(pack[5]);
	int		i;

	print::subHeaderLine("Preparing animals");
	Cat	cat;
	Dog dog;
	print::subHeaderLine("Constructing the pack");
	i = sizeof(pack) / sizeof(Animal *) - 1;
	while (i >= 0)
	{
		if (i % 2)
			pack[i] = new Cat(cat);
		else
			pack[i] = new Dog(dog);
		i--;
	}
	print::subHeaderLine("Demonstrating Deep Copy");
	dog.displayAddress();
	pack[0]->displayAddress();
	print::subHeaderLine("Deconstructing the pack");
	i = sizeof(pack) / sizeof(Animal *) - 1;
	while (i >= 0)
	{
		delete pack[i];
		i--;
	}
	print::subHeaderLine("Deconstructing the prepared animals");
}
