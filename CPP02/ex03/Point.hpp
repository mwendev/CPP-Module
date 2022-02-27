/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:26:21 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 12:49:14 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point {
public:
	Point(void);
	Point(const Point &obj);
	Point(const float x, const float y);
	Point& operator= (const Point &obj);
	~Point(void);

	Fixed	getX(void) const;
	Fixed	getY(void) const;
	void	setX(const Point &obj);
	void	setY(const Point &obj);

private:
	const Fixed x;
	const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<< (std::ostream& out, const Point &obj );

#endif