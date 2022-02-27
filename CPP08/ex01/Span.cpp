/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:51:55 by mwen              #+#    #+#             */
/*   Updated: 2022/02/23 13:28:39 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N)
{
	this->ptr = new std::vector<int>(N);
	this->ptr->clear();
}

Span::Span(const Span &obj)
{
	this->ptr = new std::vector<int>(obj.ptr->capacity());
	this->ptr->clear();
	for (unsigned int i = 0; i < obj.ptr->size(); i++)
		this->ptr->push_back(obj.ptr->at(i));
}

Span::~Span()
{
	delete this->ptr;
}

Span&	Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		if (this->ptr)
			delete this->ptr;
		this->ptr = new std::vector<int>(obj.ptr->capacity());
		this->ptr->clear();
		for (unsigned int i = 0; i < obj.ptr->size(); i++)
			this->ptr->push_back(obj.ptr->at(i));
	}
	return *this;
}

int			Span::addNumber(int element)
{
	try
	{
		if (this->ptr->size() == this->ptr->capacity())
			throw Span::TooFullException();
		else
			this->ptr->push_back(element);
		return 0;
	}
	catch (Span::TooFullException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
}

const char* Span::TooFullException::what() const throw()
{
	return "'TooFullException': addNumber() called but there is no capacity anymore";
}

const char* Span::TooShortException::what() const throw()
{
	return "'TooShortException': there are not enough of elements to get Span";
}

unsigned int	Span::shortestSpan() const
{
	try
	{
		if (this->ptr->size() < 2)
			throw Span::TooShortException();
		else
		{
			std::vector<int> tmp = *this->ptr;
			std::sort(tmp.begin(), tmp.end());
			return (unsigned int)(tmp[1] - tmp[0]);
		}
	}
	catch (Span::TooShortException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return -1;
	}
}

unsigned int	Span::longestSpan() const
{
	try
	{
		if (this->ptr->size() < 2)
			throw Span::TooShortException();
		else
		{
			std::vector<int> tmp = *this->ptr;
			std::sort(tmp.begin(), tmp.end());
			return (unsigned int)(tmp[this->ptr->size() - 1] - tmp[0]);
		}
	}
	catch (Span::TooShortException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return -1;
	}
}

void			Span::print() const
{
	std::cout << "[ ";
	for (unsigned int i = 0; i < this->ptr->size(); i++)
		std::cout << this->ptr->at(i) << " ";
	std::cout << "]" << std::endl;
}

void			Span::addRange(int from, int to, int distance)
{
	if (from >= to || to - from <= distance)
		return ;
	for (int i = from; i <= to; i += distance)
		if (this->addNumber(i))
			return;
}
