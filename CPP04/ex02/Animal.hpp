/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:44:10 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:06:38 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal {
public:
	Animal();
	Animal(const Animal &obj);
	virtual ~Animal();
	Animal& operator=(const Animal &obj);
	
	virtual std::string		getType() const = 0;
	virtual Brain*			getBrain() const = 0;
	virtual void			makeSound() const = 0;

protected:
	std::string	type;
};

#endif