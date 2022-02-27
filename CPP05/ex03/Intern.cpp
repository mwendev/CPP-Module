/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:33:33 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 13:22:09 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &obj)
{
	(void)obj;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern &obj)
{
	(void)obj;
	return *this;
}

Form	*Intern::makeShrubberyCreationForm(std::string target)
{
	Form *f_ptr = new ShrubberyCreationForm(target);
	return f_ptr;
}

Form	*Intern::makeRobotomyRequestForm(std::string target)
{
	Form *f_ptr = new RobotomyRequestForm(target);
	return f_ptr;
}

Form	*Intern::makePresidentialPardonForm(std::string target)
{
	Form *f_ptr = new PresidentialPardonForm(target);
	return f_ptr;
}

Form*	Intern::makeForm(std::string form_name, std::string target)
{
	Form* (Intern::*f_ptr[3])(std::string target) = {&Intern::makeShrubberyCreationForm, \
													&Intern::makeRobotomyRequestForm, \
													&Intern::makePresidentialPardonForm,};
	std::string	forms[3] = {"ShrubberyCreationForm", \
							"RobotomyRequestForm", \
							"PresidentialPardonForm"};

	for (int i = 0; i < 3; ++i)
	{
		if (!form_name.compare(forms[i]))
		{
			std::cout << "Intern creates " << form_name << '\n';
			return (this->*f_ptr[i])(target);
		}
	}
	std::cerr << "Invalid form: " << form_name << std::endl;
	return NULL;
}
