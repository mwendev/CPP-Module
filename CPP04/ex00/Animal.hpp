/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:44:10 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:02:11 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
public:
	Animal();
	Animal(const Animal &obj);
	virtual ~Animal();
	Animal& operator=(const Animal &obj);
	
	virtual std::string		getType() const;
	virtual void			makeSound() const;

protected:
	std::string	type;
};

#endif