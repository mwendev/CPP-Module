/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:17:49 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 22:47:00 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &obj);
	~ScavTrap(void);
	ScavTrap& operator= (const ScavTrap &obj);

	void	attack( std::string const &target );
	void	guardGate(void);

	unsigned int getEnergyPoints(void);

private:
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;
};

#endif