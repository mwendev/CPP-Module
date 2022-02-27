/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:13:03 by mwen              #+#    #+#             */
/*   Updated: 2022/02/11 23:30:06 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed &obj);
	Fixed& operator= (const Fixed &obj);
	~Fixed(void);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					value;
	const int static	fraction = 8;
};

#endif