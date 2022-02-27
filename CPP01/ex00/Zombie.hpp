/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:41:12 by mwen              #+#    #+#             */
/*   Updated: 2022/02/08 23:22:52 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>
#include <new>

class Zombie {
public:
	Zombie( std::string name );
	~Zombie( void );

	void	announce( void );

private:
	std::string	name;
};

Zombie*		newZombie( std::string name );
void		randomChump( std::string name );

#endif