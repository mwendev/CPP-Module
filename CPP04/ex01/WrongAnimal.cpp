/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:06:57 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:05:34 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("General")
{
	std::cout << "[WrongAnimal default constructor]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "[WrongAnimal copy constructor]" << std::endl;
	this->type = obj.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal destructor]" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "[WrongAnimal copy assignment operator]" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal say whaaaaaaaaat" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
