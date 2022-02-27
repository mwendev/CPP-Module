/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:18:15 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 21:33:35 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <string>
#include <iostream>

typedef struct Data {
	std::string	name;
	size_t		age;
	float		level;
} Data;

uintptr_t	serialize(Data* ptr)
{
	uintptr_t p = reinterpret_cast<std::uintptr_t>(ptr);
	return (p);
}

Data*		deserialize(uintptr_t raw)
{
	Data *p = reinterpret_cast<Data *>(raw);
	return (p);
}

int	main()
{
	Data mwen;

	mwen.name = "Mei";
	mwen.age = std::string::npos;
	mwen.level = 4.32;
	
	Data *ptr = deserialize(serialize(&mwen));

	std::cout << ptr->name << '\n';
	std::cout << ptr->age << '\n';
	std::cout << ptr->level << '\n';

	if (&mwen == ptr)
		std::cout << "Return value of deserialize() compares equal to the original pointer" << '\n';

}