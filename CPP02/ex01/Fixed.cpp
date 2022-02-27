/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:45:28 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 01:21:36 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	/* int to fixed-point int */
	std::cout << "Int constructor called" << std::endl;
	setRawBits(num << fraction);
}

Fixed::Fixed(const float fnum)
{
	/* float to fixed-point float */
	std::cout << "Float constructor called" << std::endl;
	setRawBits((int)std::roundf(fnum * (1 << fraction)));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator= (const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		value = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	return (value);
}

void	Fixed::setRawBits( int const raw )
{
	value = raw;
}

float	Fixed::toFloat( void ) const
{
	/* fixed-point to float */
	return ((float)getRawBits() / (float)(1 << fraction));
}

int		Fixed::toInt( void ) const
{
	/* fixed-point to int */
	return ((int)getRawBits() / (float)(1 << fraction));
}

std::ostream& operator<< (std::ostream& out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
