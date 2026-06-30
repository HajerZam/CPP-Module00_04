/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:09:07 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/30 13:54:47 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap    Kris("kris");
	ClapTrap    Susie("Susie");

	for (size_t i = 0; i < 6; i++)
	{
		Kris.attack("darkner");
	}
	Kris.takeDamage(125);
	std::cout << std::endl;

	for (size_t i = 0; i < 12; i++)
	{
		Susie.takeDamage(1);
		Susie.beRepaired(1);
	}
	return (0);
}