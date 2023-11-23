/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:44:49 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/10 14:13:38 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "colors.hpp"

#include <iostream>

// #include <string>

// #include <string>
// #include <cstdio>

static bool	st_direct_command(PhoneBook	*book, std::string cmd);
static void	st_reset_settings(bool *ret);

int	main(void)
{
	PhoneBook	book;
	std::string	cmd;
	bool		ret;

	std::cout	<< "\nYou open the phonebook, but notice its empty...\n"
				<< C_GRAY	<< "Add your first contact by typing ADD.\n"
				<< "Type HELP for more options.\n"
				<< C_RESET	<< std::endl;
	while (!std::cin.eof())
	{
		std::cout	<< "> "
					<< std::flush;
		getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
			break ;
		if (cmd.empty())
			continue ;
		ret = st_direct_command(&book, cmd);
		st_reset_settings(&ret);
	}
	std::cout	<< C_GRAY	<< "Closing phonebook, losing contacts forever."
				<< C_RESET	<< std::endl;
	return (0);
}

static bool	st_direct_command(PhoneBook	*book, std::string cmd)
{
	if (cmd.compare("ADD") == 0)
		return (book->commandAdd());
	if (cmd.compare("DELETE") == 0)
		return (book->commandDelete());
	if (cmd.compare("SEARCH") == 0)
		return (book->commandSearch());
	if (cmd.compare("FILL") == 0)
		book->commandFill();
	else if (cmd.compare("HELP") == 0)
		book->commandHelp();
	else
		std::cout	<< C_GRAY	<< "Invalid input. Try HELP\n";
	return (true);
}

static void	st_reset_settings(bool *ret)
{
	if (*ret == false)
	{
		std::cout	<< C_GRAY	<< "\nReturning to Phonebook..."
					<< C_RESET	<< "\n";
		*ret = true;
	}
	if (std::cin.eof())
	{
		std::cin.clear();
		clearerr(stdin);
	}
	std::cout	<< C_RESET	<< std::flush;
}
