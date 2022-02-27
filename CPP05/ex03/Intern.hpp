/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:19:16 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 12:56:00 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <string>
# include <iostream>
# include <exception>
# include <new>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &obj);
	~Intern();
	Intern&	operator=(const Intern &obj);

	Form	*makeShrubberyCreationForm(std::string target);
	Form	*makeRobotomyRequestForm(std::string target);
	Form	*makePresidentialPardonForm(std::string target);
	Form	*makeForm(std::string form_name, std::string target);
};

#endif