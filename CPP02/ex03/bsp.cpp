/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:02:46 by mwen              #+#    #+#             */
/*   Updated: 2022/02/13 19:39:19 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	getArea(Point v1, Point v2, Point v3)
{
	float	v1_x = v1.getX().toFloat();
	float	v1_y = v1.getY().toFloat();
	float	v2_x = v2.getX().toFloat();
	float	v2_y = v2.getY().toFloat();
	float	v3_x = v3.getX().toFloat();
	float	v3_y = v3.getY().toFloat();

	float	area = (fabs(((v1_x - v3_x) * (v2_y - v3_y)) - ((v2_x - v3_x) * (v1_y - v3_y)))/2);
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	totalArea = getArea(a, b, c);
	float	area1 = getArea(point, a, b);
	float	area2 = getArea(point, a, c);
	float	area3 = getArea(point, b, c);

	if (area1 + area2 + area3 == totalArea)
		if (area1 && area2 && area3)
			return (true);
	return (false);
}
