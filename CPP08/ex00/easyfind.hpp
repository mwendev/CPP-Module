/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:02:18 by mwen              #+#    #+#             */
/*   Updated: 2022/02/20 17:19:27 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <cstddef>
# include <iostream>
# include <algorithm>
# include <vector>

template <typename T>
void easyfind(T container, int element)
{
	std::vector<int>::iterator it = std::find(container.begin(), container.end(), element);

	if ( it != container.end() )
		std::cout << "Element \'" << element << "\' is in the following position: " << std::distance(container.begin(), it) << std::endl;
	else
		std::cout << "Element \'" << element << "\' was not not found in the given container" << std::endl;

}

#endif