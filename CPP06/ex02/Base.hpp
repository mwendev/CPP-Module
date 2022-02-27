/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:35:10 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 21:39:06 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <iostream>
# include <string>

class Base {
public:
	virtual ~Base();
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif