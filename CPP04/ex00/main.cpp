/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 16:15:23 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/05/06 17:22:10 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "print.hpp"
#include "colors.hpp"

#include <iostream>
// std::

int		ex00Subject(void);
void	ex00Custom(void);
void	seeNSay(const Animal *seen);

int main()
{
	ex00Subject();
	ex00Custom();
}

int	ex00Subject(void)
{
	print::headerLine("Exercise 00: Polymorphism");
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

print::subHeaderLine("Added to avoid leaks");
delete meta;
delete j;
delete i;
return 0;
}

void	ex00Custom(void)
{
	print::headerLine("Exercise 00: Polymorphism - custom tests");
	print::subHeaderLine("Correct Animal");
	const Animal	*animal;
	
	animal = new Animal();
	seeNSay(animal);
	delete animal;
	animal = new Dog();
	seeNSay(animal);
	delete animal;
	animal = new Cat();
	seeNSay(animal);
	delete animal;
	print::subHeaderLine("Wrong Animal");
	const WrongAnimal *wrong = new WrongCat();
	animal = (Animal *)wrong;
	seeNSay(animal);
	delete animal;
}

void	seeNSay(const Animal *seen)
{
	std::cout	<< "The "	
				<< C_ORANGE	<< seen->getType()
				<< C_RESET	<< " says \"";
	seen->makeSound();
	std::cout	<< "\"."	<< std::endl;
}
