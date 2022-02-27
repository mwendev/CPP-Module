/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:18:00 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 19:25:19 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	print_states(ClapTrap &obj)
{
	std::cout << obj.getName() << std::endl;
	std::cout << "\t Hit points: " << obj.getHitPoints() << std::endl;
	std::cout << "\t Energy points: " << obj.getEnergyPoints() << std::endl;
	std::cout << "\t Attack damage: " << obj.getAttackDamage() << std::endl << std::endl;
}

int	main()
{
	/* test: default constructor and name constructor*/
	ClapTrap	a;
	ClapTrap	b("CL0P-TP");

	/* test: setName() */
	a.setName("CL4P-TP");
	print_states(a);
	print_states(b);

	/* test: attack(), beRepaired()*/
	for (int i = 0; i < 9; i++)
	{
		a.attack(b.getName());
		if (i % 3 == 0)
			b.beRepaired(1);
	}

	/* test: energy points and hit points are calculated */
	print_states(a);
	print_states(b);

	/* test: copy constructor, takeDamage(), energy point too low to act */
	ClapTrap	c(a);
	c.takeDamage(5);
	c.beRepaired(1);
	c.attack(b.getName());
	print_states(c);

	/* test: copy assigment operator */
	c = b;

	/* test: hit point too low to act*/
	b.takeDamage(11);
	b.attack(a.getName());
	print_states(b);
}
