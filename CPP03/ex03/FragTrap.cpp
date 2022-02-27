/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:35:05 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 22:46:10 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name = "";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "[FragTrap default constructor]" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "[FragTrap name constructor for " << name << "]" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	std::cout << "[FragTrap copy constructor for " << this->name << "]" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap destructor for " << this->name << "]" << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap &obj)
{
	std::cout << "[FragTrap copy assignment operator for " << this->name << "]" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "A FragTrap named " << this->name << " is requesting a highfive!" << std::endl;
}

unsigned int FragTrap::getHitPoints(void)
{
	return (this->hitPoints);
}

unsigned int FragTrap::getAttackDamage(void)
{
	return (this->attackDamage);
}