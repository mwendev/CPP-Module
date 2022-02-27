/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:10:30 by mwen              #+#    #+#             */
/*   Updated: 2022/02/19 22:21:44 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap(T &a, T &b)
{
	T temp (a);
	a = b;
	b = temp;
}

template <typename T>
T	min(T a, T b)
{
	return a >= b ? b : a;
}

template <typename T>
T	max(T a, T b)
{
	return a > b ? a : b;
}
