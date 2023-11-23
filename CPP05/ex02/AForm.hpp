/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

# include <string>
// std::string
# include <exception>
// std::exception

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;

		virtual void	action(void) const = 0;

	protected:

	public:
		AForm(const std::string name, int signGrade, int execGrade);
		AForm(const AForm &src);
		virtual ~AForm(void) = 0;

		void	beSigned(Bureaucrat &bc);
		void	execute(Bureaucrat &bc) const;
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
		class GeneralException: public std::exception
		{
			private:
				std::string message;
			public:
				GeneralException(std::string msg);
				const char *what() const throw();
		};

		AForm	&operator=(const AForm &src);
};

std::ostream	&operator<<(std::ostream &out, const AForm &src);

#endif
