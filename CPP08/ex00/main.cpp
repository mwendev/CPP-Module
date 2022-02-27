/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:04:44 by mwen              #+#    #+#             */
/*   Updated: 2022/02/20 17:25:55 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int>	T;

	T.push_back(2); // position 0
	T.push_back(3); // position 1
	T.push_back(5); // position 2
	T.push_back(7); // position 3
	T.push_back(11); // position 4
	T.push_back(13); // position 5
	T.push_back(17); // position 6
	T.push_back(19); // position 7
	T.push_back(23); // position 8

	for (int i = 0; i < 30; i++)
		easyfind(T, i);
	return 0;
}
