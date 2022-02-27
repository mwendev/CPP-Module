/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:30:02 by mwen              #+#    #+#             */
/*   Updated: 2022/02/17 01:22:52 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const AMateria &obj)
{
	this->type = obj.type;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (this->type);
}

void		AMateria::use(ICharacter& target)
{
	(void)target;
}
