/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:41:41 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 12:14:59 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <new>

int	main()
{
	{
		Bureaucrat	amy("Amy", 1);
		std::cout << "=====Constructor Test=====\n";
		ShrubberyCreationForm s("Wolfsburg");
		std::cout << "**s**" << '\n' << s << '\n';
		s.beSigned(amy);
		ShrubberyCreationForm s1;
		std::cout << "**s1**" << '\n' << s1 << '\n';
		
		s1 = s;
		std::cout << "**s1 after copy**" << '\n' << s1 << '\n';
		
		ShrubberyCreationForm s2(s);
		std::cout << "**s2 with copy constructor**" << '\n' << s2 << '\n';
	}
	{
		std::cout << "=====Function Test=====\n";
		Bureaucrat	amy("Amy", 50);

		Form		*s = new ShrubberyCreationForm("Wolfsburg");
		s->beSigned(amy);
		s->execute(amy);
		std::cout << "------------------------------------------------\n";

		Form		*r = new RobotomyRequestForm("Vabot");
		s->beSigned(amy);
		amy.executeForm(*r);
		r->beSigned(amy);
		r->execute(amy);
		for (int i = 0; i < 5; i++)
			++amy;
		amy.executeForm(*r);

		std::cout << "------------------------------------------------\n";
		
		Form		*p = new PresidentialPardonForm("Someone");
		p->beSigned(amy);
		for (int i = 0; i < 41; i++)
			++amy;
		p->beSigned(amy);
		amy.executeForm(*p);
		
		delete s;
		delete r;
		delete p;
	}
}