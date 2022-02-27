/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:48:10 by mwen              #+#    #+#             */
/*   Updated: 2022/02/22 19:18:31 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	{
		Array<int>	a1;
		Array<int>	a2(8);

		for (int i = 0; i < 8; i++)
			a2[i] = 1;

		a2[7] = 42;
		std::cout << a2[7] << std::endl;

		a2[9] = 2 ;//out of bounds test

		a1 = a2;//copy assignment operator test
		std::cout << a1[7] << std::endl;
		std::cout << a1[5] << std::endl;

		Array<int> a3(a2);//copy constructor test
		std::cout << a3[7] << std::endl;
		std::cout << a3[5] << std::endl;
	}
	std::cout << "-----------------------------------------------------\n";
	{
		Array<char>	a1;
		Array<char>	a2(8);

		for (int i = 0; i < 8; i++)
			a2[i] = 'a';

		a2[7] = 'b';
		std::cout << a2[7] << std::endl;

		a2[9] = 'c';//out of bounds test

		a1 = a2;//copy assignment operator test
		std::cout << a1[7] << std::endl;
		std::cout << a1[5] << std::endl;

		Array<char> a3(a2);//copy constructor test
		std::cout << a3[7] << std::endl;
		std::cout << a3[5] << std::endl;
	}

	return 0;
}