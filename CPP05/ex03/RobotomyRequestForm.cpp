/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:43:01 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 11:46:19 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("sometarget", "RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, "RobotomyRequestForm", 74, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : Form(obj.getTarget(), obj.getName(), obj.getRequiredGradeSign(), obj.getRequiredGradeExec())
{
	this->setSigned(obj.getSignedStatus());
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
	{
		this->getTarget() = obj.getTarget();
		this->setSigned(obj.getSignedStatus());
	}
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	try
	{
		if (!this->getSignedStatus())
			throw FormNotSignedException();
		else if (this->getRequiredGradeExec() < b.getGrade())
			throw GradeTooLowException();
		else
		{
			std::srand(std::time(nullptr));
			std::cout << " * DRRR DRRRRRRRRRRRRRR   DRRRRRRRRR  DRRRRRRRRRRRRR * " << std::endl;
			std::cout << " * DRRRRRRRR   TUT   BRRRRRRRRRRR   TUT   DRRRRRRRRR * " << std::endl;
			std::cout << " * DRRR TUTTUTTUT DRRRRRRRRRRR   DRRRRRRRRRRRRR  TUT * " << std::endl;
			int	rand = std::rand();
			if (rand % 2)
				std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
			else
				std::cout << this->getTarget() << " has been robotomized unsuccessfully... :(" << std::endl;
		}
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
