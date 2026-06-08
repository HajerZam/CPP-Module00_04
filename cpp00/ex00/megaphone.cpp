/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:55:19 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/03 20:55:19 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    // Loop through each argument
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];  // convert C string to C++ string
        for (int j = 0; j < (int)arg.size(); j++)
            arg[j] = std::toupper(arg[j]);  // uppercase
        std::cout << arg;
    }
    std::cout << std::endl;
    return 0;
}