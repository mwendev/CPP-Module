/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 23:03:22 by mwen              #+#    #+#             */
/*   Updated: 2022/02/10 14:50:12 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	terminate(std::string str, std::ifstream &in, std::ofstream &out)
{
	if (!str.empty())
		std::cout << str << std::endl;
	if (in.good())
		in.close();
	if (out.good())
		out.close();
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		s1;
	std::string		s2;
	std::string		buff;
	size_t			pos = 0;
	char			c;

	if (argc != 4)
		return (terminate("Invalid input", infile, outfile));

	/*open infile and check existance and read to buff*/
	infile.open(argv[1]);
	if (!infile.is_open())
		return (terminate("Error: please check if the first argument is valid", infile, outfile));
	else
		while ((c = infile.get()) && infile.good())
			buff.insert(buff.end(), c);

	s1 = argv[2];
	s2 = argv[3];

	/*open outfile*/
	outfile.open((std::string)argv[1] + (std::string)".replace", std::ifstream::out);

	/*replace s1 with s2*/
	while((pos = buff.find(s1)) != buff.npos)
	{
		buff = buff.erase(pos, s1.length());
		buff.insert(pos, s2);
	}

	/*write to outfile*/
	outfile << buff;

	/*close files*/
	infile.close();
	outfile.close();
}
