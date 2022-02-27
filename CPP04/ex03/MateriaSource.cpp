/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:26:56 by mwen              #+#    #+#             */
/*   Updated: 2022/02/17 01:29:34 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int	i = 0; i < 4; i++)
		this->learnt[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	for(int	i = 0; i < 4; i++)
		if (obj.learnt[i])
			this->learnt[i] = obj.learnt[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for(int	i = 0; i < 4; i++)
		if (this->learnt[i])
			delete this->learnt[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &obj)
{
	if (this != &obj)
	{
		for(int	i = 0; i < 4; i++)
		{
			if (this->learnt[i])
			{
				delete this->learnt[i];
				this->learnt[i] = 0;
			}
		}
		for(int	i = 0; i < 4; i++)
		{
			if (obj.learnt[i])
				this->learnt[i] = obj.learnt[i]->clone();
		}
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "Learning failed: Materia does not exist" << std::endl;
		return ;
	}
	for(int	i = 0; i < 4; i++)
	{
		if (!this->learnt[i])
		{
			this->learnt[i] = m;
			std::cout << "Learnt " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "Learning " << m->getType() << " failed: reached max capacity" << std::endl;
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for(int	i = 0; i < 4; i++)
	{
		if (this->learnt[i] && !this->learnt[i]->getType().compare(type))
		{
			std::cout << "Materia " << type << " created" << std::endl;
			return (this->learnt[i]);
		}
	}
	std::cout << "Creating Materia failed: type not learnt yet" << std::endl;
	return (0);
}
