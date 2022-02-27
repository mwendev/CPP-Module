/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:59:43 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 11:46:25 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("sometarget", "PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, "PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : Form(obj.getTarget(), obj.getName(), obj.getRequiredGradeSign(), obj.getRequiredGradeExec())
{
	this->setSigned(obj.getSignedStatus());
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this != &obj)
	{
		this->getTarget() = obj.getTarget();
		this->setSigned(obj.getSignedStatus());
	}
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	try
	{
		if (!this->getSignedStatus())
			throw FormNotSignedException();
		else if (this->getRequiredGradeExec() < b.getGrade())
			throw GradeTooLowException();
		else
			std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (FormNotSignedException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
