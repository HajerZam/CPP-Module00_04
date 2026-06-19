/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:58:21 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/19 11:49:58 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "DEBUG:" << std::endl;
    harl.complain("DEBUG");
    std::cout << "INFO:" << std::endl;
    harl.complain("INFO");
    std::cout << "WARNING:" << std::endl;
    harl.complain("WARNING");
    std::cout << "ERROR:" << std::endl;
    harl.complain("ERROR");
    
    return (0);
}
