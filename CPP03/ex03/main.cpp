/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:18:00 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 23:19:45 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	print_states(DiamondTrap &obj)
{
	std::cout << obj.getName() << std::endl;
	std::cout << "\t ClapTrap name: " << obj.ClapTrap::getName() << std::endl;
	std::cout << "\t Hit points: " << obj.getHitPoints() << std::endl;
	std::cout << "\t Energy points: " << obj.getEnergyPoints() << std::endl;
	std::cout << "\t Attack damage: " << obj.getAttackDamage() << std::endl << std::endl;
}

int	main()
{
	/* test: anme constructor */
	DiamondTrap	a("ShineBrightLikeADiamond");
	print_states(a);

	/* test: default constructor */
	DiamondTrap b;

	/* test: copy assignment operator */
	b = a;

	/* test: copy construcor*/
	DiamondTrap c(a);

	/* test: if DimondTrap can call all parent functions */
	a.attack("someone");
	a.takeDamage(10);
	a.beRepaired(1);
	a.highFivesGuys();
	a.guardGate();
	print_states(a);

	/* test: whoAmI() */
	a.whoAmI();
}
