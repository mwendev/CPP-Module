/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:30:09 by mwen              #+#    #+#             */
/*   Updated: 2022/02/22 13:05:24 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>

/* Test case: 
	./convert inf
	./convert -inf
	./convert nan
	./convert nanf
	./convert 0
	./convert 42.987
	./convert 42.0f
	./convert jwekfhkj
	./convert 1a */

class Impossible : public std::exception
{
public:
	const char *what() const throw() {return "char:\timpossible\nint:\timpossible\nfloat:\timpossible\ndouble:\timpossible";}
};

void	toChar(double value)
{	
	if (!isfinite(value))
		std::cout << "char:\t" << "impossible" << '\n';
	else if (value * 10 > static_cast<int>(value) * 10)
		std::cout << "char:\t" << "impossible" << '\n';
	else if (isprint(value))
		std::cout << "char:\t'" << static_cast<char>(value) << "'\n";
	else
		std::cout << "char:\t" << "Non displayable" << '\n';
}

void	toInt(double value)
{
	if (!isfinite(value))
		std::cout << "int:\t" << "impossible" << '\n';
	else
		std::cout << "int:\t" << static_cast<int>(value) << '\n';
}

void	toFloat(double value)
{
	if (value * 10 == static_cast<int>(value) * 10 && static_cast<char>(value) >= 0)
		std::cout << "float:\t" << value << ".0f" << '\n';
	else
		std::cout << "float:\t" << value << 'f' << '\n';
}

void	toDouble(double value)
{
	if (value * 10 == static_cast<int>(value) * 10 && static_cast<char>(value) >= 0)
		std::cout << "double:\t" << value << ".0" << '\n';
	else
		std::cout << "double:\t" << value << '\n';
}

int	main(int argc, char **argv)
{
	double		value = 0;

	if (argc == 2)
	{
		std::string	str = static_cast<std::string>(argv[1]);
		try
		{
			value = stod(str);
			if (isdigit(str[0]) && !(str.find_first_not_of("0123456789f.") == std::string::npos))
			{
				throw Impossible();
				return (1);
			}
		}
		catch(const std::exception& e)
		{
			Impossible i;
			std::cout << i.what() << '\n';
			return (1);
		}
		toChar(value);
		toInt(value);
		toFloat(value);
		toDouble(value);
	}
}
