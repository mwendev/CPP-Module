/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:31:56 by mwen              #+#    #+#             */
/*   Updated: 2022/03/02 22:39:01 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const Point &obj) : x(obj.x), y(obj.y) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point&	Point::operator= (const Point &obj)
{
	if (this != &obj)
	{
		const_cast <Fixed&> (this->x) = obj.x;
		const_cast <Fixed&> (this->y) = obj.y;
	}
	return (*this);
}

Point::~Point(void) {}

Fixed Point::getX(void) const
{
	return(x);
}

Fixed Point::getY(void) const
{
	return(y);
}

std::ostream& operator<< (std::ostream& out, const Point &obj )
{
	out << "Point(" << obj.getX().toFloat() << ", " << obj.getY().toFloat() << ") ";
	return (out);
}
