/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:47:11 by mwen              #+#    #+#             */
/*   Updated: 2022/02/09 18:16:40 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->nb_contact = 0;
	this->print_landingpage();
	this->listen_input();
	return;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::print_landingpage()
{
	std::cout << std::endl;
	std::cout << "        _________   _________        " <<std::endl;
	std::cout << "   ____/    INDEX\\ /        0 \\____   " <<std::endl;
	std::cout << " /| ------------- |  ------------ |\\ " <<std::endl;
	std::cout << "||| ------------- | ------------- |||" <<std::endl;
	std::cout << "||| ------------- | ------------- |||" <<std::endl;
	std::cout << "||| ------- ----- | ------------- |||" <<std::endl;
	std::cout << "||| --WELCOME---- | -----TO------ |||" <<std::endl;
	std::cout << "||| -----THE----- | --PHONEBOOK-- |||" <<std::endl;
	std::cout << "|||  ------------ | ----------    |||" <<std::endl;
	std::cout << "||| ------------- |  ------------ |||" <<std::endl;
	std::cout << "||| ------------- | ------------- |||" <<std::endl;
	std::cout << "||| ------------- | ------ -----  |||" <<std::endl;
	std::cout << "||| ------------  | ------------- |||" <<std::endl;
	std::cout << "|||_____________  |  _____________|||" <<std::endl;
	std::cout << "L/--------------\\\\_//---------------J" <<std::endl;
	std::cout << std::endl;
	return;
}

void	PhoneBook::listen_input()
{
	std::string	input;
	std::string string_exit ("EXIT");
	std::string string_search ("SEARCH");
	std::string string_add ("ADD");

	while (1)
	{
		std::cout << "(<>..<>) Doop Boop... What can I do for you?" << std::endl;
		std::cout << " -ADD (press 1)\n -SEARCH (press 2)\n -EXIT (press 3)\n>> ";
		getline(std::cin, input);
		if (!string_add.compare(input) || input == "1")
			this->add_contact();
		else if (!string_search.compare(input) || input == "2")
			this->search_contact();
		else if (!string_exit.compare(input) || input == "3")
		{
			std::cout << "See you next time!" << std::endl;
			return;
		}
	}
}

void	PhoneBook::add_contact()
{
	++this->nb_contact;
	if (this->nb_contact > 8)
		this->nb_contact = 1;
	if (this->contacts[this->nb_contact - 1].create_contact(this->nb_contact))
		--this->nb_contact;
	return;
}

void	PhoneBook::search_contact()
{
	std::string	input;

	if (!this->nb_contact)
		std::cout << std::endl << "(!) According to the phonebook, you don't have any friends... yet\n" << std::endl;
	else
	{
		while (1)
		{
			this->display_preview();
			std::cout << "Enter an index to view the full contact: ";
			getline(std::cin, input);
			if (input.length() == 1 && input >= "1" && input <= "8")
			{
				if (!this->contacts[std::stoi(input) - 1].print_contact(std::stoi(input)))
					return;
			}
			else
				std::cout << "(!) Invalid index" << std::endl;
		}
	}
}

void	PhoneBook::display_preview()
{
	std::cout << " __________ __________ __________ __________ " << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
		this->contacts[i].print_preview();
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}