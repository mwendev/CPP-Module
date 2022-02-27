/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:22:35 by mwen              #+#    #+#             */
/*   Updated: 2022/02/16 19:07:08 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain {
public:
	Brain();
	Brain(const Brain &obj);
	~Brain();
	Brain& operator=(const Brain &obj);

	void		setIdea(size_t index, std::string idea);
	std::string	getIdea(size_t index) const;

private:
	std::string	ideas[100];
};

#endif