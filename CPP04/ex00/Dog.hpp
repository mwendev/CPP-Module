/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:11:04 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:02:55 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	Dog(const Dog &obj);
	~Dog();
	Dog& operator=(const Dog &obj);

	std::string		getType() const;
	void			makeSound() const;

private:
	std::string	type;
};

#endif