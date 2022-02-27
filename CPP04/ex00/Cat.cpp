/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:04:54 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:02:36 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << "[Cat default constructor]" << std::endl;
}

Cat::Cat(const Cat &obj)
{
	std::cout << "[Cat copy constructor]" << std::endl;
	this->type = obj.type;
}

Cat::~Cat()
{
	std::cout << "[Cat destructor]" << std::endl;
}

Cat&	Cat::operator=(const Cat &obj)
{
	if (this != &obj)
		this->type = obj.type;
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
