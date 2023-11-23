/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:47:29 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/09 16:44:49 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

		void		printSummarySegment(std::string	segment);

	protected:

	public:
		Contact(void);
		Contact(std::string data[5]);
		Contact(const Contact &src);
		~Contact(void);

		void		setFirstName(std::string first_name);
		std::string	getFirstName(void) const;
		void		setLastName(std::string last_name);
		std::string	getLastName(void) const;
		void		setNickname(std::string nickname);
		std::string	getNickname(void) const;
		void		setPhoneNumber(std::string phonenumber);
		std::string	getPhoneNumber(void) const;
		void		setDarkestSecret(std::string secret);
		std::string	getDarkestSecret(void) const;
		void		printSummary(int index);
		void		printDetails(void);

		Contact	&operator=(const Contact &src);
};

#endif