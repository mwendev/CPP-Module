/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:18:00 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 20:56:58 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	print_states(FragTrap &obj)
{
	std::cout << obj.getName() << std::endl;
	std::cout << "\t Hit points: " << obj.getHitPoints() << std::endl;
	std::cout << "\t Energy points: " << obj.getEnergyPoints() << std::endl;
	std::cout << "\t Attack damage: " << obj.getAttackDamage() << std::endl << std::endl;
}

int	main()
{
	/* test: default construcor, name constructor */
	FragTrap	a;
	FragTrap	b("FR0P-TP");

	a.setName("FR4P-TP");
	print_states(a);
	print_states(b);

	/* test: copy constructor */
	FragTrap	c(a);
	print_states(c);

	/* test: copy assignment operator */
	c = b;

	/* test: FragTrap can call parent function */
	c.beRepaired(1);
	c.takeDamage(1);

	/* test: highFivesGuys() */
	c.highFivesGuys();
}