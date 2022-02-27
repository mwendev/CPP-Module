/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:59:21 by mwen              #+#    #+#             */
/*   Updated: 2022/02/17 00:16:11 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character : public ICharacter {
public:
	Character();
	Character(const Character &obj);
	Character(std::string name);
	~Character();
	Character&	operator=(const Character &obj);

	std::string const&	getName() const;

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void print_inventory() const;

private:
	std::string	name;
	AMateria*	inventory[4];
	AMateria*	unequipped[999];
};

#endif