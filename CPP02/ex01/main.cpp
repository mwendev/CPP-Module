/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:10:49 by mwen              #+#    #+#             */
/*   Updated: 2022/02/12 22:36:02 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Expected output:
	Default constructor called
	Int constructor called
	Float constructor called
	Copy constructor called
	Copy assignment operator called
	Float constructor called
	Copy assignment operator called
	Destructor called
	a is 1234.43
	b is 10
	c is 42.4219
	d is 10
	a is 1234 as integer
	b is 10 as integer
	c is 42 as integer
	d is 10 as integer
	Destructor called
	Destructor called
	Destructor called
	Destructor called */

int main( void ) 
{
	/* default constructor */
	Fixed a;
	/* int constructor */
	Fixed const b( 10 );
	/* float constructor */
	Fixed const c( 42.42f );
	/* copy constructor */
	Fixed const d( b );
	/* copy assignment & float constructor */
	a = Fixed( 1234.4321f );

	/* print float */
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	/* print int */
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
