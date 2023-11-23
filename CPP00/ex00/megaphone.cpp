/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 19:48:03 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/03 20:14:26 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//std

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		std::cout	<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 1;
		while (i < argc)
		{
			std::string	str = argv[i];
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			std::cout	<< str;
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
