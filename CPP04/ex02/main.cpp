/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:57:05 by mwen              #+#    #+#             */
/*   Updated: 2022/02/17 15:47:25 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "/* An abstract Class cannot be declared but a pointer of it can */" << std::endl;
	{
		/* uncomment below and you should see compile error */
		// Animal	animal;
		Animal *animalptr = new Cat();
		animalptr->makeSound();
		std::cout << "Cat's type: " << animalptr->getType() << std::endl;
		std::cout << "Cat's 42nd idea is: " << animalptr->getBrain()->getIdea(41) << std::endl;
		animalptr->getBrain()->setIdea(41, "to chase its own tail!");
		std::cout << "Cat's 42nd idea is: " << animalptr->getBrain()->getIdea(41) << std::endl;
		delete animalptr;
	}
	{
		Animal *animalptr = new Dog();
		animalptr->makeSound();
		std::cout << "Dog's type: " << animalptr->getType() << std::endl;
		std::cout << "Dog's 42nd idea is: " << animalptr->getBrain()->getIdea(41) << std::endl;
		animalptr->getBrain()->setIdea(41, "to eat food!");
		std::cout << "Dog's 42nd idea is: " << animalptr->getBrain()->getIdea(41) << std::endl;
		delete animalptr;
	}
	return 0;
}