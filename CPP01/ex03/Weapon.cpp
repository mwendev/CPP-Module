/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:32:42 by mwen              #+#    #+#             */
/*   Updated: 2022/02/11 12:48:55 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->setType(name);
}

Weapon::~Weapon(void) {}

void	Weapon::setType(std::string name)
{
	this->type = name;
}

const std::string&	Weapon::getType(void)
{
	std::string	&ref = this->type;
	return (ref);
}
