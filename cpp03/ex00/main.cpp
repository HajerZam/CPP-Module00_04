/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:09:07 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/29 12:09:07 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap    _kris("kris");
	ClapTrap    _susie("susie");

	for (size_t i = 0; i < 6; i++)
	{
		_kris.attack("darkner");
	}
	_kris.takeDamage(125);
	std::cout << std::endl;

	for (size_t i = 0; i < 12; i++)
	{
		_susie.takeDamage(1);
		_susie.beRepaired(1);
	}
	return (0);
}