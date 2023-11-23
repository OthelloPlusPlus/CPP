/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 18:30:23 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 17:38:49 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// std::
#include <fstream>
// ifstream ofstream

#define REMOVE	0
#define INSERT	1

static bool	st_validate_input(int argc, char **argv);
static void	st_convert_line(std::string *line, std::string rm, std::string ins);

int	main(int argc, char **argv)
{
	std::ifstream	in;
	std::ofstream	out;
	std::string		file;
	std::string		line;

	if (!st_validate_input(argc, argv))
		return (1);
	file = argv[1];
	in.open(file);
	out.open(file + ".replace");
	if (!in || !out)
	{
		std::cerr	<< "Error: could not open file"	<< std::endl;
		return (1);
	}
	while (std::getline(in, line))
	{
		st_convert_line(&line, argv[2], argv[3]);
		out	<< line	<< std::endl;
	}
	return (0);
}

static bool	st_validate_input(int argc, char **argv)
{
	std::string replace;
	if (!(argc == 2 || argc == 4))
	{
		std::cerr	<< "Error: invalid input.\n"
					<< "Expected input:\t"
					<< "./replace [file] ([string to remove] [string to add])"
					<< std::endl;
		return (false);
	}
	replace = argv[2];
	if (replace.length() == 0)
	{
		std::cerr	<< "Error: string to replace is not specified."
					<< std::endl;
		return (false);
	}
	return (true);
}	


static void	st_convert_line(std::string *line, std::string rm, std::string ins)
{
	unsigned long	i;
	int				len[2];

	if (!rm.compare(ins) || rm.empty())
		return ;
	len[REMOVE] = rm.length();
	len[INSERT] = ins.length();
	i = 0;
	while(1)
	{
		i = line->find(rm, i);
		if (i == std::string::npos)
			break ;
		line->erase(i, len[REMOVE]);
		line->insert(i, ins);
		i += len[INSERT];
	}
}
