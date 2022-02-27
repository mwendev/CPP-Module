/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:19:25 by mwen              #+#    #+#             */
/*   Updated: 2022/02/11 12:51:55 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), equipped(0) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &w)
{
	this->wp = &w;
	this->equipped = 1;
}

void	HumanB::attack()
{
	if (!this->equipped)
		std::cout << this->name << " is not equipped with a weapon yet." << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->wp->getType() << std::endl;
}
