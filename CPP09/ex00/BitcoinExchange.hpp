/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 19:19:37 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/08 19:19:37 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

class BitcoinExchange
{
	private:

	protected:

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &src);
};

#endif
