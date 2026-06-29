/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 09:58:20 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/29 09:58:20 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap(std::string name) : _name(name)
{
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "Default Constructor called" << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of ClapTrap" << std::endl;
}

// destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

// operator
ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	this->_name = assign._name;
	this->_hit_points = assign._hit_points;
	this->_energy_points = assign._energy_points;
	this->_attack_damage = assign._attack_damage;
	return *this;
}


//  public member functions

void    ClapTrap::attack(const std::string &target)
{
	if(!isAlive())
		std::cout << "ClapTrap" << _name << " is DEAD!" << std::endl;
	else if (!haveEnergy())
		std::cout << "ClapTrap" << _name << " is out of enegy!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_points -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((unsigned int)_hit_points <= amount)
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return;
	}
	_hit_points -= amount;
	std::cout << "ClatTrap " << _name << " take damage for " << amount << " hit points" << std::endl;
	std::cout << "Current health: " << _hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!isAlive())
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
	else if (!haveEnergy())
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
	else
	{
		_hit_points += amount;
		std::cout << "ClatTrap " << _name << " repairs itself for " << amount << " hit points" << std::endl;
		std::cout << "Current health: " << _hit_points << std::endl;
		_energy_points -= 1;
	}
}

// helpers

bool ClapTrap::haveEnergy()
{
	return (_energy_points > 0);
}

bool ClapTrap::isAlive()
{
	return (_hit_points > 0);
}
