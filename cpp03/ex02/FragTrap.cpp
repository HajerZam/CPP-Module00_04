/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:13:40 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/29 15:13:40 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap: Default Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap: Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &assign)
{
    ClapTrap::operator=(assign);
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (!haveEnergy())
    {
        std::cout << "FragTrap: " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
    _energy_points -= 1;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap: " << _name << " requests a high five!" << std::endl;
}
