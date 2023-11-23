/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:30:05 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/10 14:04:05 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contact[8];
		
		std::string	requestInfoString(std::string prompt);
		size_t		requestIndex(void);
		std::string	requestInfoNumber(std::string prompt);

		size_t		displayContactSummary(void);
		void		displayContactSummaryHead(void) const;

		void		contactAdd(std::string data[5]);
		bool		phonebookContainsContacts(void);

	protected:

	public:
		PhoneBook(void);
		PhoneBook(const PhoneBook &src);
		~PhoneBook(void);

		bool	commandAdd(void);
		void	commandFill(void);
		bool	commandDelete(void);
		bool	commandSearch(void);
		void	commandHelp(void) const;

		PhoneBook	&operator=(const PhoneBook &src);
};

#endif