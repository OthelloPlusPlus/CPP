/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:29:44 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/22 15:33:38 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
//ostream

class Fixed
{
	private:
		int					bits;
		static const int	point = 8;

	protected:

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		~Fixed(void);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
		std::bitset<32>	toRaw(void) const;

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		//assignment operators
		Fixed	&operator=(const Fixed &src);
		Fixed	operator++(int); //i++
		Fixed	&operator++(void); //++i
		Fixed	operator--(int); //i--
		Fixed	&operator--(void); //--i
		//arithmitc operators
		Fixed	operator+(const Fixed &src) const;
		Fixed	operator-(const Fixed &src) const;
		Fixed	operator*(const Fixed &src) const;
		Fixed	operator/(const Fixed &src) const;
		//relational operators (comparison)
		bool	operator>(const Fixed &src) const;
		bool	operator<(const Fixed &src) const;
		bool	operator>=(const Fixed &src) const;
		bool	operator<=(const Fixed &src) const;
		bool	operator==(const Fixed &src) const;
		bool	operator!=(const Fixed &src) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);

#endif