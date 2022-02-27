/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:12:09 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 11:46:05 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("sometarget", "ShrubberyCreationForm", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, "ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : Form(obj.getTarget(), obj.getName(), obj.getRequiredGradeSign(), obj.getRequiredGradeExec())
{
	this->setSigned(obj.getSignedStatus());
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
	{
		this->getTarget() = obj.getTarget();
		this->setSigned(obj.getSignedStatus());
	}
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	try
	{
		if (!this->getSignedStatus())
			throw FormNotSignedException();
		else if (this->getRequiredGradeExec() < b.getGrade())
			throw GradeTooLowException();
		else
		{
			std::ofstream	of;
			of.open(this->getTarget().append("_shrubbery"));
			of <<
					"      /\\      \n" <<
					"     /\\*\\     \n" <<
					"    /\\O\\*\\    \n" <<
					"   /*/\\/\\/\\   \n" <<
					"  /\\O\\/\\*\\/\\  \n" <<
					" /\\*\\/\\*\\/\\/\\ \n" <<
					"/\\O\\/\\/*/\\/O/\\\n" <<
					"      ||      \n" <<
					"      ||      \n" <<
					"      ||    \n";
			of.close();
		}
	}
	catch (GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (FormNotSignedException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
