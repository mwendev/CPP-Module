/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:35:16 by mwen              #+#    #+#             */
/*   Updated: 2022/02/14 22:45:45 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &obj);
	~FragTrap(void);
	FragTrap& operator= (const FragTrap &obj);

	void	highFivesGuys(void);

	unsigned int getHitPoints(void);
	unsigned int getAttackDamage(void);

private:
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;
};

#endif