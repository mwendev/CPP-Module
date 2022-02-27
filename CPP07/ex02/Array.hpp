/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:07:15 by mwen              #+#    #+#             */
/*   Updated: 2022/02/20 18:20:05 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <cstddef>
# include <iostream>
# include <new>

template <typename T>

class Array {
public:
	Array() : array(new T) {};

	Array(unsigned int n) : array(new T[n]), _size(n)
	{
		for (unsigned int i = 0; i < n; ++i)
			this->array[i] = 0;
	};

	Array(const Array &obj) : array(new T[obj._size])
	{
		for (unsigned int i = 0; i < obj._size; i++)
			this->array[i] = obj.array[i];
		this->_size = obj._size;
	};

	~Array() {delete[] this->array;};

	Array&	operator=(const Array &obj)
	{
		if (this != &obj)
		{
			if (this->array)
				delete[] this->array;
			this->array = new T[obj._size];
			for (unsigned int i = 0; i < obj._size; i++)
				this->array[i] = obj.array[i];
			this->_size = obj._size;
		}
		return *this;
	}

	unsigned int size() const {return this->_size;};

	T& operator[] (const unsigned int index)
	{
		try
		{
			if (index >= this->_size)
				throw std::out_of_range("Element out of limits");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		return this->array[index];
	}

	class OutofRange : public std::exception {
	public:
		const char* what() const throw() { return "Error: This element is out of the limits!";}
	};

private:
	T*				array;
	unsigned int	_size;
};
#endif