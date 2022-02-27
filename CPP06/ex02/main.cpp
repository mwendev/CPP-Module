/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:58:43 by mwen              #+#    #+#             */
/*   Updated: 2022/02/21 17:27:10 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	std::cout << "========= Random Generate Test ==========" << std::endl;
	Base *p = generate();

	identify(p);
	identify(*p);

	delete p;

	std::cout << "================ Fixed Class Test ===============" << std::endl;

	A *a_ptr = new A;
	A &a_ref = *a_ptr;
	identify(dynamic_cast<Base *>(a_ptr));
	identify(dynamic_cast<Base &>(a_ref));
	delete a_ptr;

	B *b_ptr = new B;
	B &b_ref = *b_ptr;
	identify(dynamic_cast<Base *>(b_ptr));
	identify(dynamic_cast<Base &>(b_ref));
	delete b_ptr;

	C *c_ptr = new C;
	C &c_ref = *c_ptr;
	identify(dynamic_cast<Base *>(c_ptr));
	identify(dynamic_cast<Base &>(c_ref));
	delete c_ptr;
}
