/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

# include <string>
// std::string
# include <exception>
// std::exception

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;

	protected:

	public:
		Form(const std::string name, int signGrade, int execGrade);
		Form(const Form &src);
		~Form(void);

		void	beSigned(Bureaucrat &bc);
		void	printForm(void) const;

		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

		class GradeTooHighException: public std::exception
		{
			private:
				std::string	message;
			public:
				GradeTooHighException(int grade);
				const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			private:
				std::string	message;
			public:
				GradeTooLowException(int grade);
				const char	*what() const throw();
		};

		Form	&operator=(const Form &src);
};

std::ostream	&operator<<(std::ostream &out, const Form &src);

#endif
