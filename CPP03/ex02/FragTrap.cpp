/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:35:05 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 18:55:30 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->setName("");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "[FragTrap default constructor]" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "[FragTrap name constructor for " << name << "]" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
{
	this->setName(obj.getName());
	this->setHitPoints(obj.getHitPoints());
	this->setEnergyPoints(obj.getEnergyPoints());
	this->setAttackDamage(obj.getAttackDamage());
	std::cout << "[FragTrap copy constructor for " << getName() << "]" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap destructor for " << getName() << "]" << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap &obj)
{
	std::cout << "[FragTrap copy assignment operator for " << getName() << "]" << std::endl;
	if (this != &obj)
	{
		this->setName(obj.getName());
		this->setHitPoints(obj.getHitPoints());
		this->setEnergyPoints(obj.getEnergyPoints());
		this->setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "A FragTrap named " << getName() << " is requesting a highfive!" << std::endl;
}
