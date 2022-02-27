/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:29:13 by mwen              #+#    #+#             */
/*   Updated: 2022/02/22 19:43:14 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

typedef void (*t_func)(int *n);

void	increseInt(int *n)
{
	if (*n != 2147483647)
		*n += 1;
}

typedef void (*c_func)(char *c);

void	increseChar(char *c)
{
	*c += 1;
}

int	main()
{
	int		irray[4] = {0, 1, 2, 3};
	char	crray[4] = {'a', 'b', 'c', 'd'};

	t_func func = &increseInt;
	iter(irray, 4, func);
	c_func cfunc = &increseChar;
	iter(crray, 4, cfunc);

	for(int i = 0; i < 4; i++)
		std::cout << irray[i] << " ";
	std::cout << '\n';
	
	for(int i = 0; i < 4; i++)
		std::cout << crray[i] << " ";
	std::cout << '\n';
}
