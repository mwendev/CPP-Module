/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:05:53 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:05:45 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &obj);
	virtual ~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal &obj);
	
	std::string	getType() const;
	void		makeSound() const;

protected:
	std::string	type;
};

#endif