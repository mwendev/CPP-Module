/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:33:57 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 22:47:35 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->name = "";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "[ScavTrap default constructor]" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "[ScavTrap name constructor for " << name << "]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	std::cout << "[ScavTrap copy constructor for " << this->name << "]" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap destructor for " << this->name << "]" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &obj)
{
	std::cout << "[ScavTrap copy assignment operator for " << this->name << "]" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack( std::string const &target )
{
	if (energyPoints && hitPoints)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		--energyPoints;
	}
	else
	{
		if (energyPoints)
			std::cout << "ScavTrap " << name << " doesn't have energy point anymore!" << std::endl;
		else if (hitPoints)
			std::cout << "ScavTrap " << name << " has no hit point anymore!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "A ScavTrap named " << name << " is now in Gate keeper mode!" << std::endl;
}

unsigned int ScavTrap::getEnergyPoints(void)
{
	return (this->energyPoints);
}
