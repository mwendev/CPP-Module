/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:33:57 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 18:54:33 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->setName("");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "[ScavTrap default]" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "[ScavTrap name constructor for " << name << "]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	this->setName(obj.getName());
	this->setHitPoints(obj.getHitPoints());
	this->setEnergyPoints(obj.getEnergyPoints());
	this->setAttackDamage(obj.getAttackDamage());
	std::cout << "[ScavTrap copy constructor for " << getName() << "]" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap destructor for " << getName() << "]" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &obj)
{
	std::cout << "[ScavTrap copy assignment operator for " << getName() << "]" << std::endl;
	if (this != &obj)
	{
		this->setName(obj.getName());
		this->setHitPoints(obj.getHitPoints());
		this->setEnergyPoints(obj.getEnergyPoints());
		this->setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}

void	ScavTrap::attack( std::string const &target )
{
	unsigned int	temp_energyPoint = getEnergyPoints();
	unsigned int	temp_hitPoint = getHitPoints();

	if (temp_energyPoint && temp_hitPoint)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(--temp_energyPoint);
	}
	else
	{
		if (!temp_energyPoint)
			std::cout << "ScavTrap " << getName() << " doesn't have energy point anymore!" << std::endl;
		else if (!temp_hitPoint)
			std::cout << "ScavTrap " << getName() << " has no hit point anymore!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "A ScavTrap named " << getName() << " is now in Gate keeper mode!" << std::endl;
}
