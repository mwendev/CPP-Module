/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:00:54 by mwen              #+#    #+#             */
/*   Updated: 2022/02/08 21:28:10 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : index(0) {}

Contact::~Contact() {}

int	Contact::create_contact(int index)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	number;
	std::string	secret;

	std::cout << "Enter the first name: ";
	getline(std::cin, first_name);
	if (first_name.empty())
		return (this->error_create(1, 0));
	std::cout << "Enter the last name: ";
	getline(std::cin, last_name);
	if (last_name.empty())
		return (this->error_create(1, 0));
	std::cout << "Enter the nickname: ";
	getline(std::cin, nickname);
	if (nickname.empty())
		return (this->error_create(1, 0));
	std::cout << "Enter the phone number: ";
	getline(std::cin, number);
	if (number.empty())
		return (this->error_create(1, 0));
	for (std::string::size_type i = 0; i < number.size(); i++)
		if (!std::isdigit(number[i]))
			return (this->error_create(0, 1));
	std::cout << "Tell me the darkest secret of this person ^_^: ";
	getline(std::cin, secret);
	if (secret.empty())
		return (this->error_create(1, 0));
	this->index = index;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->number = number;
	this->secret = secret;
	std::cout << "\nContact added!" << std::endl;
	return (EXIT_SUCCESS);
}

int	Contact::error_create(int empty, int not_digit)
{
	if (empty)
		std::cout << "\nYou didn't enter anything..." << std::endl;
	if (not_digit)
		std::cout << "\nWhat kind of number has any non-digit character..." << std::endl;
	std::cout << "\n(!) Adding contact failed (ˊ_ˋ)/" << std::endl;
	return (EXIT_FAILURE);
}

void	Contact::print_preview()
{
	std::string	index_string;
	if (this->index != 0)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << this->index << "|";
		std::cout << std::setw(10);
		std::cout << this->format(this->first_name) << "|";
		std::cout << std::setw(10);
		std::cout << this->format(this->last_name) << "|";
		std::cout << std::setw(10);
		std::cout << this->format(this->nickname) << "|";
		std::cout << std::endl;
	}
}

std::string	Contact::format(std::string str)
{
	std::string	temp;

	if (str.length() > 10)
		temp = str.substr(0, 9) + '.';
	else
		temp = str;
	return (temp);
}

int	Contact::print_contact(int index)
{
	std::cout << std::endl;
	if (index == this->index)
	{
		std::cout << "====Contact Info====" << std::endl;
		std::cout << "First name: " << this->first_name << std::endl;
		std::cout << "Last name: " << this->last_name << std::endl;
		std::cout << "Nickname: " << this->nickname << std::endl;
		std::cout << "Number: " << this->number << std::endl;
		std::cout << "Darkest Secret: " << this->secret << std::endl;
		std::cout << "====================" << std::endl << std::endl;
		return (EXIT_SUCCESS);
	}
	else
		std::cout << "(!) No contact data in this index yet" << std::endl;
	return (EXIT_FAILURE);
}