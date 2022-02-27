/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:10:16 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:05:59 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat")
{
	std::cout << "[WrongCat default constructor]" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj)
{
	std::cout << "[WrongCat copy constructor]" << std::endl;
	this->type = obj.type;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat destructor]" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat: mrrp mrrp" << std::endl;
}

std::string	WrongCat::getType() const
{
	return (this->type);
}