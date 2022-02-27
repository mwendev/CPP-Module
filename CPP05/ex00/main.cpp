/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:41:41 by mwen              #+#    #+#             */
/*   Updated: 2022/02/18 22:01:11 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat amy("Amy", 42);
	std::cout << amy << std::endl;

	Bureaucrat bob("Bob", 151);
	std::cout << bob << std::endl;

	Bureaucrat colin("Colin", 150);
	std::cout << colin << std::endl;

	Bureaucrat david("David", 1);
	std::cout << david << std::endl;

	Bureaucrat eason (amy);
	std::cout << eason << std::endl;

	Bureaucrat someone;
	std::cout << someone << std::endl;
	
	someone = amy;
	std::cout << someone << std::endl;

	--colin;
	++david;
	
	std::cout << colin << std::endl;
	std::cout << david << std::endl;
}