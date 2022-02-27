/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:18:00 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 20:56:33 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	print_states(ScavTrap &obj)
{
	std::cout << obj.getName() << std::endl;
	std::cout << "\t Hit points: " << obj.getHitPoints() << std::endl;
	std::cout << "\t Energy points: " << obj.getEnergyPoints() << std::endl;
	std::cout << "\t Attack damage: " << obj.getAttackDamage() << std::endl << std::endl;
}

int	main()
{
	/* test: default construcor, name constructor */
	ScavTrap	a;
	ScavTrap	b("SV0P-TP");

	a.setName("SV4P-TP");
	print_states(a);
	print_states(b);

	/* test: attack(), energy point too low to act */
	a.setEnergyPoints(0);
	a.attack(b.getName());
	
	print_states(a);

	/* test: copy constructor */
	ScavTrap	c(a);
	c.attack(b.getName());
	print_states(c);

	/* test: copy assignment operator */
	c = b;

	/* test: ScavTrap can call parent function */
	c.beRepaired(1);
	c.takeDamage(1);

	/* test: guardGate() */
	c.guardGate();
}
