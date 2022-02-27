/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:41:41 by mwen              #+#    #+#             */
/*   Updated: 2022/02/20 20:16:00 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <new>

int	main()
{
	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	std::cout << *rrf << "\n\n";
	delete rrf;

	rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Wolfsburg");
	std::cout << *rrf << "\n\n";
	delete rrf;

	rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Someone");
	std::cout << *rrf << "\n\n";
	delete rrf;
}
