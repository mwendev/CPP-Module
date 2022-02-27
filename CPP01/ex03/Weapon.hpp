/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:39:26 by mwen              #+#    #+#             */
/*   Updated: 2022/02/09 19:42:06 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>
#include <new>

class Weapon {
public:
	Weapon(std::string);
	~Weapon(void);
	const std::string	&getType(void);
	void				setType(std::string name);

private:
	std::string	type;
};

#endif