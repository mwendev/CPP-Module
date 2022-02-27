/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:20:52 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 11:45:44 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : target("something"), name("someform"), sign(false), required_grade_sign(150), required_grade_exec(150) {}

Form::Form(std::string target, std::string name, int required_grade_sign, int required_grade_exec) : target(target), name(name), sign(false), required_grade_sign(required_grade_sign), required_grade_exec(required_grade_exec)
{
	try
	{
		if (required_grade_sign > 150 || required_grade_exec > 150)
			throw Form::GradeTooLowException();
		else if (required_grade_sign < 1 || required_grade_exec < 1)
			throw Form::GradeTooHighException();
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

Form::Form(const Form &obj) : target(obj.target), name(obj.name), sign(obj.sign), required_grade_sign(obj.required_grade_sign), required_grade_exec(obj.required_grade_exec) {}

Form::~Form() {}

Form& Form::operator=(const Form &obj)
{
	if (this != &obj)
	{
		try
		{
			if (obj.required_grade_sign > 150 || obj.required_grade_exec > 150)
				throw Form::GradeTooLowException();
			else if (obj.required_grade_sign < 1 || obj.required_grade_exec < 1)
				throw Form::GradeTooHighException();
			else
			{
				this->sign = obj.sign;
				this->target = obj.target;
			}
		}
		catch (Form::GradeTooLowException& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		catch (Form::GradeTooHighException& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	return *this;
}

std::string		Form::getTarget() const
{
	return this->target;
}

std::string		Form::getName() const
{
	return this->name;
}

bool			Form::getSignedStatus() const
{
	return sign;
}

int				Form::getRequiredGradeSign() const
{
	return this->required_grade_sign;
}

int				Form::getRequiredGradeExec() const
{
	return this->required_grade_exec;
}

void				Form::setSigned(bool b)
{
	this->sign = b;
}

void			Form::beSigned(const Bureaucrat& b)
{
	try
	{
		if (this->sign)
			std::cout << this->name << " is already signed" << std::endl;
		else
		{
			b.signForm(*this);
			if (b.getGrade() > this->required_grade_sign)
				throw Form::GradeTooLowException();
			else
				this->sign = true;
		}
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw ()
{
	return "'GradeTooHighException': required grade must be in range 1-150";
}

const char* Form::GradeTooLowException::what() const throw ()
{
	return "'GradeTooLowException': required grade must be in range 1-150, or the form must be signed or executed by a sufficient bureaucrat";
}

const char* Form::FormNotSignedException::what() const throw ()
{
	return "'FormNotSignedException': the form must be signed before being executed";
}

std::ostream& operator<<(std::ostream& out, const Form &obj)
{
	out << std::boolalpha;
	out << obj.getName() << "\nSigned: " << obj.getSignedStatus() << "\nMinimum Required Grade to sign: " << obj.getRequiredGradeSign() << "\nMinimum Required Grade to execute: " << obj.getRequiredGradeExec();
	return (out);
}
