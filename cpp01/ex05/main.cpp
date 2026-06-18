/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:58:21 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/18 12:12:41 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl Harl();

    std::std::cout << "DEBUG:" << std::endl;
    harl.complain("DEBUG");
    std::std::cout << "INFO:" << std::endl;
    harl.complain("INFO");
    std::std::cout << "WARNING:" << std::endl;
    harl.complain("WARNING");
    std::std::cout << "ERROR:" << std::endl;
    harl.complain("ERROR");
    
    return (0);
}
