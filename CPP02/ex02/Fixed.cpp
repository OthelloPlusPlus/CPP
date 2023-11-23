/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 20:34:08 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 18:33:54 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"

#include <iostream>
// std::
#include <cmath>
// roundf

/** ************************************************************************ **\
 * 
 * 	Constructors
 * 
\* ************************************************************************** */

Fixed::Fixed(void): bits(0)
{
	// std::cout	<< C_DGREEN	<< "Fixed: "
	// 			<< C_GREEN	<< "Default "
	// 			<< C_DGREEN	<< "constructor called."
	// 			<< C_RESET	<< std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout	<< C_DGREEN	<< "Fixed: "
	// 			<< C_GREEN	<< "Int "
	// 			<< C_DGREEN	<< "constructor called."
	// 			<< C_RESET	<< std::endl;
	this->setRawBits(value << this->point);
}

Fixed::Fixed(const float value)
{
	// std::cout	<< C_DGREEN	<< "Fixed: "
	// 			<< C_GREEN	<< "Float "
	// 			<< C_DGREEN	<< "constructor called."
	// 			<< C_RESET	<< std::endl;
	this->setRawBits(roundf(value * (1 << this->point)));
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout	<< C_DGREEN	<< "Fixed: "
	// 			<< C_GREEN	<< "Copy "
	// 			<< C_DGREEN	<< "constructor called."
	// 			<< C_RESET	<< std::endl;
	*this = src;
}

/** ************************************************************************ **\
 * 
 * 	Deconstructors
 * 
\* ************************************************************************** */

Fixed::~Fixed(void)
{
	// std::cout	<< C_DRED	<< "Fixed: "
	// 			<< C_RED	<< "Destructor "
	// 			<< C_DRED	<< "called."
	// 			<< C_RESET	<< std::endl;
}

/** ************************************************************************ **\
 * 
 * 	Member Functions
 * 
\* ************************************************************************** */

int		Fixed::getRawBits(void) const
{
	// std::cout	<< C_DGRAY	<< "Fixed: "
	// 			<< C_LGRAY	<< __func__
	// 			<< C_DGRAY	<< " member function called."
	// 			<< C_RESET	<< std::endl;
	return (this->bits);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout	<< C_DGRAY	<< "Fixed: "
	// 			<< C_LGRAY	<< __func__
	// 			<< C_DGRAY	<< " member function called."
	// 			<< C_RESET	<< std::endl;
	this->bits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->bits) / (1 << this->point));
}

int		Fixed::toInt(void) const
{
	return (this->bits >> this->point);
}

std::bitset<32>	Fixed::toRaw(void) const
{
	std::bitset<32>	raw(this->bits);
	return (raw);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

/** ************************************************************************ **\
 * 
 * 	Operators
 * 
\* ************************************************************************** */

Fixed	&Fixed::operator=(const Fixed &src)
{
	// std::cout	<< C_LCYAN	<< "Fixed: "
	// 			<< C_DCYAN	<< "Copy assignement "
	// 			<< C_LCYAN	<< __func__
	// 			<< C_DCYAN	<< " called."
	// 			<< C_RESET	<< std::endl;
	if (this == &src)
		return (*this);
	this->bits = src.getRawBits();
	return (*this);
}

Fixed	Fixed::operator++(int) //i++
{
	Fixed new_member(*this);

	this->bits++;
	return (new_member);
}

Fixed	&Fixed::operator++(void) //++i
{
	this->bits++;
	return (*this);
}

Fixed	Fixed::operator--(int) //i--
{
	Fixed new_member(*this);

	this->bits--;
	return (new_member);
}

Fixed	&Fixed::operator--(void) //--i
{
	this->bits--;
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &src) const
{
	Fixed new_member(this->toFloat() + src.toFloat());

	return (new_member);
}

Fixed	Fixed::operator-(const Fixed &src) const
{
	Fixed new_member(this->toFloat() - src.toFloat());

	return (new_member);
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	Fixed new_member(this->toFloat() * src.toFloat());

	return (new_member);
}

Fixed	Fixed::operator/(const Fixed &src) const
{
	Fixed new_member(this->toFloat() / src.toFloat());

	return (new_member);
}

bool	Fixed::operator>(const Fixed &src) const
{
	if (this->bits > src.getRawBits())
		return (true);
	return (false);
	
}

bool	Fixed::operator<(const Fixed &src) const
{
	if (this->bits < src.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &src) const
{
	if (this->bits >= src.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &src) const
{
	if (this->bits <= src.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &src) const
{
	if (this->bits == src.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &src) const
{
	if (this->bits != src.getRawBits())
		return (true);
	return (false);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return (out);
}
