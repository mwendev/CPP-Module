/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:39:42 by mwen              #+#    #+#             */
/*   Updated: 2022/02/11 10:50:03 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main()
{
	Karen	karen;
	
	karen.complain("DEBUG");
	std::cout << std::endl;
	karen.complain("INFO");
	std::cout << std::endl;
	karen.complain("WARNING");
	std::cout << std::endl;
	karen.complain("ERROR");
	std::cout << std::endl;
}
