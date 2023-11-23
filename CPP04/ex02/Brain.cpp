/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 20:45:12 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "colors.hpp"

#include <iostream>
// std::

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Brain::Brain(void)
{
	this->addIdeas(sizeof(Brain::ideas) / sizeof(std::string));
	std::cout	<< C_DGREEN	<< "He is thinking \""
				<< C_GREEN	<< this->getRandomThought()
				<< C_DGREEN	<< "\"."
				<< C_RESET	<< std::endl;
}

Brain::Brain(const Brain &src)
{
	*this = src;
	std::cout	<< C_DGREEN	<< "Copy constructor "
				<< C_GREEN	<< "Brain"
				<< C_DGREEN	<< " called."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Brain::~Brain(void)
{
	std::cout	<< C_DRED	<< " got distracted..."
				<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

//	https://www.philosophybasics.com/general_quotes.html
void	Brain::addIdeas(int	amount)
{
	this->ideas[--amount] = "I don't want to set the world on fire";
	this->ideas[--amount] = "I do want to set the world on fire";
	this->ideas[--amount] = "The unexamined life is not worth living";
	this->ideas[--amount] = "Whereof one cannot speak, thereof one must be silent";
	this->ideas[--amount] = "Entities should not be multiplied unnecessarily";
	this->ideas[--amount] = "The life of man (in a state of nature) is solitary, poor, nasty, brutish, and short";
	this->ideas[--amount] = "I think therefore I am";
	this->ideas[--amount] = "Cogito, ergo sum";
	this->ideas[--amount] = "He who thinks great thoughts, often makes great errors";
	this->ideas[--amount] = "We live in the best of all possible worlds";
	this->ideas[--amount] = "What is rational is actual and what is actual is rational";
	this->ideas[--amount] = "God is dead! He remains dead! And we have killed him";
	this->ideas[--amount] = "There is but one truly serious philosophical problem, and that is suicide";
	this->ideas[--amount] = "One cannot step twice in the same river";
	this->ideas[--amount] = "The greatest happiness of the greatest number is the foundation of morals and legislation";
	this->ideas[--amount] = "To be is to be perceived";
	this->ideas[--amount] = "Esse est percipi";
	this->ideas[--amount] = "Happiness is not an ideal of reason but of imagination";
	this->ideas[--amount] = "No man's knowledge here can go beyond his experience";
	this->ideas[--amount] = "God is not willing to do everything, and thus take away our free will and that share of glory which belongs to us";
	this->ideas[--amount] = "Liberty consists in doing what one desires";
	this->ideas[--amount] = "It is undesirable to believe a proposition when there is no ground whatever for supposing it true";
	this->ideas[--amount] = "Even while they teach, men learn";
	this->ideas[--amount] = "There is only one good, knowledge, and one evil, ignorance";
	this->ideas[--amount] = "If God did not exist, it would be necessary to invent Him";
	while (amount > 0)
		this->ideas[--amount] = "I want food...";
}

std::string	Brain::getRandomThought(void) const
{
	return (this->ideas[rand() / 23 % (sizeof(Brain::ideas) / sizeof(std::string))]);
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Brain	&Brain::operator=(const Brain &src)
{
	if (this == &src)
		return (*this);

	return (*this);
}
