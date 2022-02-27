/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:57:09 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:02:20 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("General")
{
	std::cout << "[Animal default constructor]" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "[Animal copy constructor]" << std::endl;
	this->type = obj.type;
}

Animal::~Animal()
{
	std::cout << "[Animal destructor]" << std::endl;
}

Animal& Animal::operator=(const Animal &obj)
{
	std::cout << "[Animal copy assignment operator]" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Animal::makeSound() const {}

std::string	Animal::getType() const
{
	return (this->type);
}
