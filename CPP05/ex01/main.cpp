/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:41:41 by mwen              #+#    #+#             */
/*   Updated: 2022/02/18 22:28:39 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	amy("Amy", 42);

	Form		visa_application("Visa Application", 15, 40);
	std::cout << visa_application << std::endl;
	
	Form		address_registration("Meldebescheinigung", 150, 150);
	std::cout << address_registration << std::endl;

	Form		form(address_registration);
	std::cout << form << std::endl;

	form.beSigned(amy);
	std::cout << form << std::endl;

	form.beSigned(amy);

	visa_application.beSigned(amy);
	std::cout << visa_application << std::endl;

	Form		copy;
	copy = form;
	std::cout << copy << std::endl;

	form.beSigned(amy);
}