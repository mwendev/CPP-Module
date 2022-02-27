/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:23:43 by mwen              #+#    #+#             */
/*   Updated: 2022/02/10 19:29:04 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() {}
Karen::~Karen() {}

void Karen::complain( std::string level )
{	
	f_ptr		fp[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 5; i++)
	{
		if (level == levels[i] || i == 4)
		{
			switch (i)
			{
				case 0: std::cout << "[ " << levels[0] << " ]" << std::endl;
						(this->*fp[0])();
						std::cout << std::endl;
				case 1: std::cout << "[ " << levels[1] << " ]" << std::endl;
						(this->*fp[1])();
						std::cout << std::endl;
				case 2: std::cout << "[ " << levels[2] << " ]" << std::endl;
						(this->*fp[2])();
						std::cout << std::endl;
				case 3: std::cout << "[ " << levels[3] << " ]" << std::endl;
						(this->*fp[3])();
						std::cout << std::endl;
						return ;
				default: std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
			}
		}
	}
}

void	Karen::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
