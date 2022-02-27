/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:52:33 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 18:51:29 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap default constructor]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : name(obj.name), hitPoints(obj.hitPoints), energyPoints(obj.energyPoints), attackDamage(obj.attackDamage)
{
	std::cout << "[ClapTrap copy constructor for " << name << "]" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap name constructor for " << name << "]" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap destructor for " << name << "]" << std::endl;
}

ClapTrap&	ClapTrap::operator= (const ClapTrap &obj)
{
	std::cout << "Hi this is the copy assignment operator for " << name << "]" << std::endl;
	if (this != &obj)
	{
		this->setName(obj.name);
		this->setHitPoints(obj.hitPoints);
		this->setEnergyPoints(obj.energyPoints);
		this->setAttackDamage(obj.attackDamage);
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints && hitPoints)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		--energyPoints;
	}
	else
	{
		if (!energyPoints)
			std::cout << "ClapTrap " << name << " doesn't have energy point anymore!" << std::endl;
		else if (!hitPoints)
			std::cout << "ClapTrap " << name << " has no hit point anymore!" << std::endl;
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has got " << amount << " of damage!" << std::endl;
	hitPoints = (int)hitPoints - (int)amount < 0 ? 0 : hitPoints - amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints && hitPoints)
	{
		std::cout << "ClapTrap " << name << " has been repaired, recovering " << amount << " of hit points and reducing 1 energy point!" << std::endl;
		hitPoints = hitPoints + amount > 100 ? 100 : hitPoints + amount;
		--energyPoints;
	}
	else
	{
		if (!energyPoints)
			std::cout << "ClapTrap " << name << " doesn't have energy point anymore!" << std::endl;
		else if (!hitPoints)
			std::cout << "ClapTrap " << name << " has no hit point anymore!" << std::endl;
	}
}

std::string		ClapTrap::getName(void) const
{
	return (name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (attackDamage);
}

void			ClapTrap::setName(std::string name)
{
	this->name = name;
}

void			ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
}

void			ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
}

void			ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
}