/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:19:12 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/18 11:50:21 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	// checking arguments
	if (argc < 4)
	{
		std::cout << "usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string search = argv[2];
	search = replaceNL(search);
	std::string replace = argv[3];
	replace = replaceNL(replace);

	// oepning filestream
	std::ifstream infile;
	infile.open(filename.c_str());
	if (infile.fail())
	{
		std::cout << "Error opening file!" << std::endl;
		return (1);
	}
	std::ofstream outfile;
	outfile.open((filename + ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << "Error creating output file!" << std::endl;
		return (1);
	}


	// reading file and replacing
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();

	// replacing all occurrences of search with replace
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