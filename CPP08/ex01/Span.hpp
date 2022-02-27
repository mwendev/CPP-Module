/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:26:04 by mwen              #+#    #+#             */
/*   Updated: 2022/02/20 19:37:05 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <string>
# include <vector>

class Span {
public:
	Span();
	Span(unsigned int N);
	Span(const Span &obj);
	~Span();
	Span&	operator=(const Span &obj);

	int				addNumber(int element);
	void			addRange(int from, int to, int distance);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;
	void			print() const;

	class TooFullException : public std::exception {
	public:
		const char* what() const throw();
	};

	class TooShortException : public std::exception {
	public:
		const char* what() const throw();
	};

private:
	std::vector<int> *ptr;
};

#endif