/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:38:15 by mwen              #+#    #+#             */
/*   Updated: 2022/02/09 22:52:08 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : name(name), wp(&w) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->wp->getType() << std::endl;
}
