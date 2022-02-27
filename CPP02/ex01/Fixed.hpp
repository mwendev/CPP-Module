/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:13:03 by mwen              #+#    #+#             */
/*   Updated: 2022/02/12 23:37:37 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float fnum);
	Fixed(const Fixed &obj);
	Fixed& operator= (const Fixed &obj);
	~Fixed(void);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					value;
	const int static	fraction = 8;
};

std::ostream& operator<< (std::ostream& out, const Fixed &obj );

#endif