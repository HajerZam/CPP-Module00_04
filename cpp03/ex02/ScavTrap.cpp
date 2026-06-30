/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:48:15 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/30 13:41:04 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ORTHODOX CANONICAL FORM
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

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap: Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
    ClapTrap::operator=(assign);
    std::cout << "ScavTrap: Assignment operator called" << std::endl;
    return *this;
}

// Overridden attack(): note this version only checks haveEnergy()

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

// ScavTrap-only ability. No equivalent exists in ClapTrap or FragTrap
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: " << _name << " is now in Gate keeper mode." << std::endl;
}
