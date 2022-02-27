/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:38:41 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 23:15:48 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->name = "";
	ClapTrap::setName(name.append("_clap_name"));
	this->hitPoints = FragTrap::getHitPoints();
	this->energyPoints = ScavTrap::getEnergyPoints();
	this->attackDamage = FragTrap::getAttackDamage();
	std::cout << "[DiamondTrap default constructor]" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	ClapTrap::setName(name.append("_clap_name"));
	this->hitPoints = FragTrap::getHitPoints();
	this->energyPoints = ScavTrap::getEnergyPoints();
	this->attackDamage = FragTrap::getAttackDamage();
	std::cout << "[DiamondTrap name constructor for " << this->name << "]" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
	this->name = obj.name;
	ClapTrap::setName(obj.ClapTrap::getName());
	this->hitPoints = FragTrap::getHitPoints();
	this->energyPoints = ScavTrap::getEnergyPoints();
	this->attackDamage = FragTrap::getAttackDamage();
	std::cout << "[DiamondTrap copy constructor for " << this->name << "]" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[DiamondTrap destructor for " << this->name << "]" << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		ClapTrap::setName(obj.ClapTrap::getName());
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	std::cout << "[DiamondTrap copy assignment operator for " << this->name << "]" << std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return (this->name);
}
