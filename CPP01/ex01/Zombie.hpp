/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:41:12 by mwen              #+#    #+#             */
/*   Updated: 2022/02/08 23:23:23 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>
#include <new>

class Zombie {
public:
	Zombie( void );
	~Zombie( void );

	void	announce( void );
	void	setName(std::string name);

private:
	std::string	name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif