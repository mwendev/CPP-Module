/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:11:39 by mwen              #+#    #+#             */
/*   Updated: 2022/02/15 13:01:53 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : type("Dog")
{
	std::cout << "[Dog default constructor]" << std::endl;
}

Dog::Dog(const Dog &obj)
{
	std::cout << "[Dog copy constructor]" << std::endl;
	this->type = obj.type;
}

Dog::~Dog(void)
{
	std::cout << "[Dog destructor]" << std::endl;
}

Dog&	Dog::operator=(const Dog &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: woof woof" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (this->type);
}