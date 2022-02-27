/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:58:10 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:04:52 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <new>

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &obj);
	~Cat();
	Cat& operator=(const Cat &obj);

	std::string		getType() const;
	Brain*			getBrain() const;
	void			makeSound() const;

private:
	std::string	type;
	Brain		*b;
};

#endif