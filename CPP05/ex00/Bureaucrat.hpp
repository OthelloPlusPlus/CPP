/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
// std::string
#include <exception>
// std::exception

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

		void validateVariables(void) const;

	protected:

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);

		void	signForm(Form &form);
		void	promote(void);
		void	demote(void);

		const std::string	getName(void) const;
		int					getGrade(void) const;

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

		Bureaucrat	&operator=(const Bureaucrat &src);
		Bureaucrat	operator++(int);	//Bureaucrat++
		Bureaucrat	&operator++(void);	//++Bureaucrat
		Bureaucrat	operator--(int);	//Bureaucrat--
		Bureaucrat	&operator--(void);	//--Bureaucrat
};

#include "Form.hpp"

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#endif
