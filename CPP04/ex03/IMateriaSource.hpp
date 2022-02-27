/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:17:22 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 17:19:04 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include "AMateria.hpp"
# include <string>

class IMateriaSource {
public:
	virtual ~IMateriaSource() {};
	virtual void learnMateria( AMateria* materia ) = 0; 
	virtual AMateria* createMateria( std::string const &type ) = 0;
};

#endif