/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:57:05 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 14:35:34 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "/* Cat and Dog should have Brain */" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << "--------------------------------------------" << std::endl;
	{
		std::cout << "/* create an array of Animal and fill in Cats and Dogs */" << std::endl;
		const Animal *animals[10];
	
		for (int i = 0; i < 10; i++)
		{
			std::cout << i;
			if (i % 2)
				animals[i] = new Cat;
			else
				animals[i] = new Dog;
		}
		std::cout << "/* delete Cats and Dogs as animals */" << std::endl;
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	std::cout << "--------------------------------------------" << std::endl;
	{
		std::cout << "/* Deep copy in Cat */" << std::endl;
		Cat *Simba = new Cat;
		std::cout << "Simba's 42nd idea is: " << Simba->getBrain()->getIdea(41) << std::endl;
		Simba->getBrain()->setIdea(41, "to eat food!");
		std::cout << "Simba's 42nd idea is: " << Simba->getBrain()->getIdea(41) << std::endl;

		Cat *Cleo = Simba;
		Cleo->getBrain()->getIdea(41);
		std::cout << "Cleo's 42nd idea is: " << Cleo->getBrain()->getIdea(41) << std::endl;

		Cat Shadow ( *Simba );
		Shadow.getBrain()->getIdea(41);
		std::cout << "Shadow's 42nd idea is: " << Shadow.getBrain()->getIdea(41) << std::endl;
	
		delete Simba;
	}
	std::cout << "--------------------------------------------" << std::endl;
	{
		std::cout << "/* Deep copy in Dog */" << std::endl;
		Dog *Simon = new Dog;
		std::cout << "Simon's 42nd idea is: " << Simon->getBrain()->getIdea(41) << std::endl;
		Simon->getBrain()->setIdea(41, "to chase its own tail!");
		std::cout << "Simon's 42nd idea is: " << Simon->getBrain()->getIdea(41) << std::endl;
	
		Dog *Cooper = Simon;
		Cooper->getBrain()->getIdea(41);
		std::cout << "Cooper's 42nd idea is: " << Cooper->getBrain()->getIdea(41) << std::endl;
	
		Dog Rocky ( *Simon );
		Rocky.getBrain()->getIdea(41);
		std::cout << "Rocky's 42nd idea is: " << Rocky.getBrain()->getIdea(41) << std::endl;
	
		delete Simon;
	}
	
	return 0;
}