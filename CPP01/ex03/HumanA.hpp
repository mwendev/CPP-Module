/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:26:09 by mwen              #+#    #+#             */
/*   Updated: 2022/02/09 22:51:37 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon &w);
	~HumanA();

	void	attack(void);

private:
	std::string	name;
	Weapon		*wp;
};

#endif