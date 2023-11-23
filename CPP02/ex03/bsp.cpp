/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 18:38:35 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/11 20:20:02 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <cmath>

float	heronsFormula(Point const a, Point const b, Point const c);
float	lineLength(Point const a, Point const b);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	surface;
	float	surfaceA;
	float	surfaceB;
	float	surfaceC;

	surface = heronsFormula(a, b, c);
	surfaceA = heronsFormula(point, b, c);
	surfaceB = heronsFormula(a, point, c);
	surfaceC = heronsFormula(a, b, point);

	if (surface  + 0.0001f < surfaceA + surfaceB + surfaceC)
		return (false);
	return (true);
}

/**
 * @brief
 * s = (A + B + C) / 2
 * area = √ (s(s - A)(s - B)(s - C))
 * 
 * @param a	point a
 * @param b	point b
 * @param c	point c
 * @return	float area
 */
float	heronsFormula(Point const a, Point const b, Point const c)
{
	float	lengthA;
	float	lengthB;
	float	lengthC;
	float	semiPerim;

	lengthA = lineLength(b, c);
	lengthB = lineLength(a, c);
	lengthC = lineLength(a, b);
	semiPerim = (lengthA + lengthB + lengthC) / 2;
	return (sqrt(semiPerim * \
				(semiPerim - lengthA) * \
				(semiPerim - lengthB) * \
				(semiPerim - lengthC)));
}

/**
 * @brief 
 * Pythagorean theorem
 * 	length = √ ((bx-ax)²+(by-ay)²)
 * 
 * @param a	a
 * @param b	b
 * @return Fixed length
 */
float	lineLength(Point const a, Point const b)
{
	return (sqrt(pow(b.getX() - a.getX(), 2) + \
				pow(b.getY() - a.getY(), 2)));
}
