/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:37:38 by mwen              #+#    #+#             */
/*   Updated: 2022/02/17 01:33:09 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << "=====Class Ice and Cure=====" << std::endl;
		Character	zelda("Zelda");
		AMateria*	c = new Cure;
		AMateria*	i = new Ice;

		std::cout << "Cure type: " << (*c).getType() << std::endl;
		std::cout << "Ice type: " << (*i).getType() << std::endl;

		c->use(zelda);
		i->use(zelda);

		std::cout << "=====Class Character=====" << std::endl;
		zelda.equip(c);
		zelda.equip(c);

		std::cout << "/* Use/Unequip Materia */" << std::endl;
		Character	link("Link");
		zelda.use(0, link);
		zelda.use(-1, link);
		zelda.use(3, link);
		zelda.unequip(0);
		zelda.unequip(-1);
		zelda.unequip(3);

		std::cout << "/* Over equip for class Character */" << std::endl;
		zelda.equip(c);
		zelda.equip(c);
		zelda.equip(i);
		zelda.equip(i);

		std::cout << "/* Copy constructor & copy assignment constructor */" << std::endl;
		Character me(zelda);
		zelda.print_inventory();
		me.print_inventory();

		me = link;
		link.print_inventory();
		me.print_inventory();

		delete c;
		delete i;

		std::cout << "=====Class MateriaSource=====" << std::endl;
		MateriaSource a;

		std::cout << "/* Over learn */" << std::endl;
		a.learnMateria(new Ice());
		a.learnMateria(new Cure());
		a.learnMateria(new Ice());
		a.learnMateria(new Cure());
		a.learnMateria(new Ice());

		std::cout << "/* Copy constructor & copy assignment constructor */" << std::endl;
		MateriaSource b(a);

		zelda.equip(b.createMateria("cure"));
		zelda.use(0, link);

		MateriaSource d;
		b = d;
		zelda.equip(b.createMateria("cure"));
		zelda.use(1, link);

		std::cout << "/* Error Management */" << std::endl;
		d.createMateria("hwkjefh");
	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	return 0;
}