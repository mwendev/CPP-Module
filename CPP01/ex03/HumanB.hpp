/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:56:47 by mwen              #+#    #+#             */
/*   Updated: 2022/02/11 12:51:15 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &w);
	void	attack();

private:
	std::string	name;
	Weapon		*wp;
	int			equipped;
};

#endif