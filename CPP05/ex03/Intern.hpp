/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
// std::string
# include <exception>
// std::exception

# include "AForm.hpp"

typedef struct s_knownForms
{
	std::string	name;
	AForm		*(*constructor)(std::string);
} t_knownForms;

class Intern
{
	private:
		static t_knownForms	knownForms2[];

		std::string	convertName(std::string &name) const;

	protected:

	public:
		Intern();
		Intern(const Intern &src);
		~Intern(void);

		AForm *makeForm(std::string form, std::string target) const;

		class	FormNameError: public std::exception
		{
			private:
				std::string	message;
			public:
				FormNameError(std::string name);
				const char	*what() const throw();
		};

		Intern	&operator=(const Intern &src);
};

#endif
