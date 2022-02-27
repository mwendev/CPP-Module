/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:07:37 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 21:55:51 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include "ICharacter.hpp"
# include <string>
# include <iostream>

class ICharacter;

class AMateria {
public:
	AMateria();
	AMateria(const AMateria &obj);
	AMateria(std::string const &type);
	virtual ~AMateria();
	AMateria& operator=(const AMateria &obj);
	
	std::string const&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:
	std::string	type;
};

#endif