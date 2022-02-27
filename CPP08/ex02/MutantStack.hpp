/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:58:36 by mwen              #+#    #+#             */
/*   Updated: 2022/02/21 18:55:12 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <stack>
# include <iostream>
# include <iterator>

template <class T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}
	MutantStack(const MutantStack &obj) { *this = obj; }
	~MutantStack() {}
	MutantStack& operator= (const MutantStack &obj)
	{
		if (this != &obj)
			*this = obj;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return std::stack<T>::c.begin(); }

	iterator end() { return std::stack<T>::c.end(); }
};

#endif