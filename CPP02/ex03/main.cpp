/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:10:49 by mwen              #+#    #+#             */
/*   Updated: 2022/03/02 22:39:18 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point	a(0, 3);
	Point	b(2, 1);
	Point	c(-2, -3);

	std::cout << std::boolalpha;

	std::cout << "False cases - vertices: " << std::endl;
	std::cout << "\t" << a << "result: " << bsp(a, b, c, a) << std::endl;
	std::cout << "\t" << b << "result: " << bsp(a, b, c, b) << std::endl;
	std::cout << "\t" << c << "result: " << bsp(a, b, c, c) << std::endl << std::endl;

	std::cout << "False cases - Points on the edge: " << std::endl;
	Point	d(1, 2);
	Point	e(-1, 0);
	Point	f(1, 2);

	std::cout << "\t" << d << "result: " << bsp(a, b, c, d) << std::endl;
	std::cout << "\t" << e << "result: " << bsp(a, b, c, e) << std::endl;
	std::cout << "\t" << f << "result: " << bsp(a, b, c, f) << std::endl << std::endl;

	std::cout << "False cases - Points outside: " << std::endl;
	Point	g(1.5f, 2);
	Point	h(-2, -4);
	Point	i(-1, 2);

	std::cout << "\t" << g << "result: " << bsp(a, b, c, g) << std::endl;
	std::cout << "\t" << h << "result: " << bsp(a, b, c, h) << std::endl;
	std::cout << "\t" << i << "result: " << bsp(a, b, c, i) << std::endl << std::endl;


	std::cout << "True cases - Points inside:  " << std::endl;
	Point	j(0, 0);
	Point	k(-1, -1.78f);
	Point	l(0.53f, 1.43f);

	std::cout << "\t" << j << "result: " << bsp(a, b, c, j) << std::endl;
	std::cout << "\t" << k << "result: " << bsp(a, b, c, k) << std::endl;
	std::cout << "\t" << l << "result: " << bsp(a, b, c, l) << std::endl << std::endl;

}
