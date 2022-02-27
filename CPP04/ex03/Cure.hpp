/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:22:05 by mwen              #+#    #+#             */
/*   Updated: 2022/02/17 01:10:05 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure &obj);
	~Cure();
	Cure& operator=(const Cure &obj);

	Cure*	clone() const;
	void	use(ICharacter& target);
};

#endif