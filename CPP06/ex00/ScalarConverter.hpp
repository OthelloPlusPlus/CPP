/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:37:13 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 13:39:19 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
// std::string

class ScalarConverter
{
	private:
		static std::string	value;

		ScalarConverter(void){}
		~ScalarConverter(void){}

		template <typename T>
		static void convertTemplate(void);
		static void	setCout(void);

	public:
		ScalarConverter(const ScalarConverter &src) = delete;
		ScalarConverter	&operator=(const ScalarConverter &src) = delete;

		static void convert(std::string value);

		explicit operator char();
		template <typename T>
		operator T();
};

#endif
