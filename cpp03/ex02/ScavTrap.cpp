/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:48:15 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/29 14:48:15 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap: Default Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!haveEnergy())
	{
		std::cout << "ScavTrap: " << _name << " is out of energy!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	_energy_points -= 1;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: " << _name << " is now in Gate keeper mode." << std::endl;
}
