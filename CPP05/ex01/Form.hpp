/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:59:48 by mwen              #+#    #+#             */
/*   Updated: 2022/02/18 22:21:53 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {
public:
	Form();
	Form(std::string name, int required_grade_sign, int required_grade_exec);
	Form(const Form &obj);
	~Form();
	Form& operator=(const Form &obj);

	std::string		getName(void) const;
	bool			getSignedStatus(void) const;
	int				getRequiredGradeSign(void) const;
	int				getRequiredGradeExec(void) const;

	void			beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception {
	public:
		const char * what () const throw ();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char * what () const throw ();
	};

private:
	std::string const	name;
	bool				sign;
	int	const			required_grade_sign;
	int	const			required_grade_exec;
};

std::ostream& operator<<(std::ostream& out, const Form &obj);

#endif