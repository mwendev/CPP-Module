/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:59:09 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:06:51 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain default constructor]" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "[Brain copy constructor]" << std::endl;
	std::copy(obj.ideas, obj.ideas + 100, this->ideas);
}

Brain::~Brain()
{
	std::cout << "[Brain destructor]" << std::endl;
}

Brain& Brain::operator=(const Brain &obj)
{
	std::cout << "[Brain copy assignment operator]" << std::endl;
	if (this != &obj)
		std::copy(obj.ideas, obj.ideas + 100, this->ideas);
	return (*this);
}

void	Brain::setIdea(size_t index, std::string idea)
{
	if (index < 100)
		this->ideas[index] = idea;
	else
		std::cout << "invalid index" << std::endl;
}

std::string	Brain::getIdea(size_t index) const
{
	if (index < 100)
		return (this->ideas[index]);
	else
		return ("invalid index\n");
}
