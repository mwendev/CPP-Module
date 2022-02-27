/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:26:00 by mwen              #+#    #+#             */
/*   Updated: 2022/02/17 01:12:24 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	this->type = "cure";
}

Cure::Cure(const Cure &obj)
{
	(void)obj;
	this->type = "cure";
}

Cure::~Cure(void) {}

Cure& Cure::operator=(const Cure &obj)
{
	(void)obj;
	return (*this);
}

Cure*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
