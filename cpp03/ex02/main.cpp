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

#include "FragTrap.hpp"

int main() {
	/*ClapTrap    _kris("kris");
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
	}*/

	/*ScavTrap _lancer("Lancer");
    _lancer.attack("Kris");
    _lancer.guardGate();*/
	
	FragTrap _ralsei("Ralsei");
    _ralsei.attack("Lancer");
    _ralsei.highFivesGuys();
	return (0);
}