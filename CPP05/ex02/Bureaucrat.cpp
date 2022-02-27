/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:18:39 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 11:35:19 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(0), grade(0) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooHighException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooLowException();
		else
			this->grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		this->grade = 150;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		this->grade = 150;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
	{
		try
		{
			if (obj.grade > 150)
				throw Bureaucrat::GradeTooHighException();
			else if (obj.grade < 1)
				throw Bureaucrat::GradeTooLowException();
			else
				this->grade = obj.grade;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
			this->grade = 150;
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
			this->grade = 150;
		}
	}
	return *this;
}

Bureaucrat&	Bureaucrat::operator++()
{
	try
	{
		if (this->grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->grade--;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return *this;
}

Bureaucrat&	Bureaucrat::operator--()
{
	try
	{
		if (this->grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->grade++;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return this->name;
}

int			Bureaucrat::getGrade() const
{
	return this->grade;
}

void		Bureaucrat::signForm(Form& f) const
{
	if (this->grade <= f.getRequiredGradeSign())
		std::cout << this->name << " signed " << f.getName() << std::endl;
	else
		std::cout << this->name << " cannot sign " << f.getName() << " because their grade is too low to sign this form" << std::endl;
}

void			Bureaucrat::executeForm(Form const& f)
{
	f.execute(*this);
	if (f.getSignedStatus() && this->grade <= f.getRequiredGradeExec())
		std::cout << this->getName() << " executes " << f.getName() << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "'GradeTooHighException': grade must be in range 1-150";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "'GradeTooLowException': grade must be in range 1-150";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade: " << obj.getGrade(); 
	return out;
}
