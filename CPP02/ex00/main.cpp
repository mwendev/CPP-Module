/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:10:49 by mwen              #+#    #+#             */
/*   Updated: 2022/02/11 23:29:57 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Expected output:
	Default constructor called
	Copy constructor called
	Copy assignment operator called // <-- This line may be missing depending on your implementation
	getRawBits member function called
	Default constructor called
	Copy assignment operator called
	getRawBits member function called
	getRawBits member function called
	0
	getRawBits member function called
	0
	getRawBits member function called
	0
	Destructor called
	Destructor called
	Destructor called */

int main( void )
{
	/* default constructor */
	Fixed a;
	/* copy constructor */
	Fixed b( a );
	Fixed c;
	/* assignment */
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
