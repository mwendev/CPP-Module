/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:45:28 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 12:52:22 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {}

Fixed::Fixed(const int num)
{
	/* int to fixed-point int */
	setRawBits(num << fraction);
}

Fixed::Fixed(const float fnum)
{
	/* float to fixed-point float */
	setRawBits((int)std::roundf(fnum * (1 << fraction)));
}

Fixed::Fixed(const Fixed &obj)
{
	value = obj.value;
}

Fixed& Fixed::operator= (const Fixed &obj)
{
	if (this != &obj)
		value = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {}

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

bool	Fixed::operator> 	( const Fixed &obj ) const
{
	return (value > obj.getRawBits());
}

bool	Fixed::operator< 	( const Fixed &obj ) const
{
	return (value < obj.getRawBits());
}

bool	Fixed::operator>=	( const Fixed &obj ) const
{
	return (value >= obj.getRawBits());
}

bool	Fixed::operator<=	( const Fixed &obj ) const
{
	return (value <= obj.getRawBits());
}

bool	Fixed::operator!=	( const Fixed &obj ) const
{ 
	return (value != obj.getRawBits());
}

bool	Fixed::operator== ( const Fixed &obj ) const 
{ 
	return (value == obj.getRawBits());
}

Fixed	Fixed::operator+	( const Fixed &obj ) const
{
	return (toFloat() + obj.toFloat());
}

Fixed	Fixed::operator-	( const Fixed &obj ) const
{
	return (toFloat() - obj.toFloat());
}

Fixed	Fixed::operator*	( const Fixed &obj ) const
{
	return (toFloat() * obj.toFloat());
}

Fixed	Fixed::operator/	( const Fixed &obj ) const
{
	return (toFloat() / obj.toFloat());
}

Fixed&	Fixed::operator++	( void )
{
	value++;
	return (*this);
}

Fixed&	Fixed::operator--	( void )
{
	value--;
	return (*this);
}

Fixed	Fixed::operator++	( int )
{
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed	Fixed::operator--	( int )
{
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed&	Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return (obj1 > obj2 ? obj2 : obj1);
}

const	Fixed&	Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 > obj2 ? obj2 : obj1);
}

Fixed&	Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}

const	Fixed&	Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}
