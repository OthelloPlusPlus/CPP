/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 13:42:09 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/03/31 18:59:55 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include "colors.hpp"
#include "print.hpp"

#include <iostream>
// std::
#include <iomanip>
// std::setw()

#include <bitset>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void			test_single(Point const a, Point const b, Point const c, Point const point);
void			test_loop(Point const a, Point const b, Point const c);
static float	lowest_float(float a, float b, float c);
static float	highest_float(float a, float b, float c);
// static void		print_info(std::string msg, std::string info);

int	main(void)
{
	const Point	a(0, 0);
	const Point	b(3, 0);
	const Point	c(0, 4);

	// print::headerLine("Single Tests");
	// test_single(a, b, c, Point(1, 1.1333));//centroid (inside)
	// test_single(a, b, c, Point(0, 0));//vertex
	// test_single(a, b, c, Point(3, 0));//vertex
	// test_single(a, b, c, Point(0, 4));//vertex
	// test_single(a, b, c, Point(1.5, 0));//edge
	// test_single(a, b, c, Point(0, 2));//edge
	// test_single(a, b, c, Point(1.5, 2));//edge
	// test_single(a, b, c, Point(1.6, 2.1));//outside
	// test_single(a, b, c, Point(3, 4));//far outside
	// test_single(a, b, c, Point(6, 8));//far outside
	print::headerLine("Test full triangle");
	test_loop(a, b, c);
	test_loop(a, Point(5, 0), Point(3.2, 2.4));
	test_loop(Point(0.5, 0.5), Point(2.3, 0), Point(-1, 4.2));
}

void	test_single(Point const a, Point const b, Point const c, Point const point)
{
	print::subHeaderLine("Single point in triangle");
	if (bsp(a, b, c, point) == true)
		std::cout	<< "point "
					<< point.getX()	<< " "	<< point.getY()
					<< " is inside the triangle"
					<< std::endl;
	else
		std::cout	<< "point "
					<< point.getX()	<< " "	<< point.getY()
					<< " is " C_RED "NOT" C_RESET " inside the triangle"
					<< std::endl;
}

void	test_loop(Point const a, Point const b, Point const c)
{
	float	x;
	float	y;
	float	lowest_x;
	float	lowest_y;
	float	highest_x;

	lowest_x = lowest_float(a.getX(), b.getX(), c.getX()) - 0.3;
	highest_x = highest_float(a.getX(), b.getX(), c.getX()) + 0.3;
	x = lowest_x;
	lowest_y = lowest_float(a.getY(), b.getY(), c.getY()) - 0.3;
	y = highest_float(a.getY(), b.getY(), c.getY()) + 0.3;

	print::subHeaderLine("Full triangle");
	std::cout	<< "\n"	<< std::setw(8)	<< std::setprecision(2)	<< y	<<"\t";
	while (y > lowest_y)
	{
		const Point	point(x, y);
		if (bsp(a, b, c, point))
			std::cout	<< " ";
		else
			std::cout	<< "X";
		x += 0.1f;
		if (x > highest_x)
		{
			std::cout	<< "\t"	<< y << std::endl;
			x = lowest_x;
			y -= 0.1f;
			std::cout	<< std::setw(8)	<< y	<<"\t";
		}
	}
}

static float	lowest_float(float a, float b, float c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= c)
		return (b);
	return (c);
}

static float	highest_float(float a, float b, float c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= c)
		return (b);
	return (c);
}
