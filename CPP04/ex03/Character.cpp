/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:14:42 by mwen              #+#    #+#             */
/*   Updated: 2022/02/17 01:21:35 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for(int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	for(int i = 0; i < 999; i++)
		this->unequipped[i] = 0;
}

Character::Character(const Character &obj)
{
	std::cout << "Copy constructor from " << obj.getName() << std::endl;

	this->name = obj.name;
	for (int i = 0; i < 4; i++)
		if (obj.inventory[i])
			this->inventory[i] = obj.inventory[i]->clone();
	for(int i = 0; i < 999; i++)
		if (obj.unequipped[i])
			this->unequipped[i] = obj.unequipped[i]->clone();
}

Character::Character(std::string name) : name(name)
{
	for(int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	for(int i = 0; i < 999; i++)
		this->unequipped[i] = 0;
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	for(int i = 0; i < 999; i++)
		if (this->unequipped[i])
			delete this->unequipped[i];
}

Character&	Character::operator=(const Character &obj)
{
	std::cout << "Copy assignment operator from " << obj.getName() << std::endl;

	if (this != &obj)
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				delete this->inventory[i];
				this->inventory[i] = 0;
			}
		}
		for(int i = 0; i < 999; i++)
		{
			if (this->unequipped[i])
			{
				delete this->unequipped[i];
				this->unequipped[i] = 0;
			}
		}
		this->name = obj.name;
		for (int i = 0; i < 4; i++)
			if (obj.inventory[i])
				this->inventory[i] = obj.inventory[i]->clone();
		for(int i = 0; i < 999; i++)
			if (obj.unequipped[i])
				this->unequipped[i] = obj.unequipped[i]->clone();
	}
	return (*this);
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Equip failed: Materia does not exist" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m->clone();
			std::cout << "Successfully equipped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
		std::cout << "Equip failed: Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0 || !this->inventory[idx])
		std::cout << "Unequip failed: Materia does not exist" << std::endl;
	else
	{
		for(int i = 0; i < 999; i++)
		{
			if (!this->unequipped[i])
			{
				this->unequipped[i] = this->inventory[idx];
				break;
			}
		}
		this->inventory[idx] = 0;
		std::cout << "Successfully unequipped inventory slot " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || idx < 0 || !this->inventory[idx])
		std::cout << "Use failed: Materia does not exist" << std::endl;
	else
		this->inventory[idx]->use(target);
}

void	Character::print_inventory() const
{
	std::cout << this->name << "'s inventory:" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		std::cout << "[Slot " << i << "] ";
		if (this->inventory[i])
			std::cout << "equipped" << std::endl;
		else
			std::cout << "empty" << std::endl;
	}
}
