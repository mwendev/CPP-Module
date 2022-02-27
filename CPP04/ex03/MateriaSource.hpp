/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:15:12 by mwen              #+#    #+#             */
/*   Updated: 2022/02/17 01:14:37 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <string>
# include <iostream>

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource &obj);
	~MateriaSource();
	MateriaSource&	operator=(const MateriaSource &obj);

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

private:
	AMateria*	learnt[4];
};

#endif