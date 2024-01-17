/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_c.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohengelm <ohengelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:20:51 by ohengelm          #+#    #+#             */
/*   Updated: 2024/01/17 18:20:57 by ohengelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE_C_HPP
# define SIZE_C_HPP

#include <cstddef>
//size_t

class size_c
{
	private:
		size_t	value;
		static size_t	compares;

	public:
		size_c(void): value(0){};
		size_c(size_t value): value(value){};
		size_c(const size_c &cpy) {*this = cpy;};

		static size_t	getCompares(void) {return size_c::compares;};
		static void		resetCompares(void) {size_c::compares = 0;};

		size_c	&operator=(const size_c &src){this->value = src.value; return (*this);};
		size_c	&operator=(const size_t &value){this->value = value; return (*this);};
		bool	operator==(const size_c &comp) {++size_c::compares; return (this->value == comp.value);};
		bool	operator>(const size_c &comp) {++size_c::compares; return (this->value > comp.value);};
		bool	operator>=(const size_c &comp) {++size_c::compares; return (this->value >= comp.value);};
		bool	operator<=(const size_c &comp) {++size_c::compares; return (this->value <= comp.value);};
		bool	operator<(const size_c &comp) {++size_c::compares; return (this->value < comp.value);};
		operator size_t() const {return (this->value);};
};

size_t	size_c::compares = 0;

#endif
