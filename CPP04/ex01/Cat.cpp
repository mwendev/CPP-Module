/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:04:54 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:04:40 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << "[Cat default constructor]" << std::endl;
	this->b = new Brain();
}

Cat::Cat(const Cat &obj)
{
	std::cout << "[Cat copy constructor]" << std::endl;
	this->b = new Brain(*(obj.b));
}

Cat::~Cat()
{
	std::cout << "[Cat destructor]" << std::endl;
	delete b;
}

Cat&	Cat::operator=(const Cat &obj)
{
	std::cout << "[Cat copy assignment operator]" << std::endl;
	if (this != &obj)
	{
		delete b;
		this->b = new Brain(*(obj.b));
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat: mrrp mrrp" << std::endl;
}

std::string	Cat::getType() const
{
	return (this->type);
}

Brain*	Cat::getBrain() const
{
	return (this->b);
}
