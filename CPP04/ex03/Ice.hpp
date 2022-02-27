/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:00:11 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 21:57:08 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice &obj);
	~Ice();
	Ice& operator=(const Ice &obj);

	Ice*	clone() const;
	void	use(ICharacter& target);
};

#endif