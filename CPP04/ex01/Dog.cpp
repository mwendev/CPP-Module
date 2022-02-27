/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:11:39 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:05:05 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : type("Dog")
{
	std::cout << "[Dog default constructor]" << std::endl;
	this->b = new Brain();
}

Dog::Dog(const Dog &obj)
{
	std::cout << "[Dog copy constructor]" << std::endl;
	this->b = new Brain(*(obj.b));
}

Dog::~Dog()
{
	std::cout << "[Dog destructor]" << std::endl;
	delete b;
}

Dog&	Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
		delete b;
		this->b = new Brain(*(obj.b));
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog: woof woof" << std::endl;
}

std::string	Dog::getType() const
{
	return (this->type);
}

Brain*	Dog::getBrain() const
{
	return (this->b);
}
