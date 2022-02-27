/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:59:48 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 10:53:48 by mwen             ###   ########.fr       */
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
	Form(std::string target, std::string name, int required_grade_sign, int required_grade_exec);
	Form(const Form &obj);
	virtual ~Form();
	Form& operator=(const Form &obj);

	std::string		getTarget() const;
	std::string		getName() const;
	bool			getSignedStatus() const;
	int				getRequiredGradeSign() const;
	int				getRequiredGradeExec() const;
	void			setSigned(bool);
	void			beSigned(const Bureaucrat& b);
	virtual void	execute(const Bureaucrat& b) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char * what () const throw ();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char * what () const throw ();
	};

	class FormNotSignedException : public std::exception {
	public:
		const char * what () const throw ();
	};

private:
	std::string			target;
	std::string const	name;
	bool				sign;
	int	const			required_grade_sign;
	int	const			required_grade_exec;
};

std::ostream& operator<<(std::ostream& out, const Form &obj);

#endif