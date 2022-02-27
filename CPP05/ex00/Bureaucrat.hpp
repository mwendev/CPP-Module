/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:55:25 by mwen              #+#    #+#             */
/*   Updated: 2022/02/18 21:39:50 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &obj);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat &obj);

	Bureaucrat&	operator++();
	Bureaucrat&	operator--();

	std::string	getName() const;
	int			getGrade() const;

	class GradeTooHighException : public std::exception {
	public:
		const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char * what () const throw ();
	};

private:
	std::string const	name;
	int					grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj);

#endif