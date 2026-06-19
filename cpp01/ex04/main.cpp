/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:19:12 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/19 11:15:07 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		std::cout << "usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string search = argv[2];
	std::string replace = argv[3];

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error opening file!" << std::endl;
		return (1);
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error creating output file!" << std::endl;
		return (1);
	}

	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();

	if (search.empty())
	{
		outfile << content;
		return (0);
	}
	for (size_t cur = 0; cur < content.length(); cur++)
	{
		if (content.substr(cur).find(search) == 0)
		{
			cur += search.length() - 1;
			outfile << replace;
		}
		else
			outfile << content[cur];
	}
	return (0);
}
