/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:19:12 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/19 13:23:41 by halzamma         ###   ########.fr       */
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

	// open the input file for reading
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error opening file!" << std::endl;
		return (1);
	}
	// open the output file for writing
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error creating output file!" << std::endl;
		return (1);
	}
	// read the entire content of the input file into a stringstream
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();
	// if the search string is empty, write the original content to the output file and exit
	if (search.empty())
	{
		outfile << content;
		return (0);
	}
	// going through the content string and replace all occurrences of the search string with the replace string
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
