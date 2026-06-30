/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 09:58:20 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/30 13:54:47 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//  Default constructor: runs whenever a ClapTrap or any derived class
ClapTrap::ClapTrap(std::string name) : _name(name) // a member init list (": _name(name)") to set _name directly
{
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "Default Constructor called" << std::endl;
}

// Copy constructor: runs when a new ClapTrap is built FROM an existing 
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy; // dereferences that pointer, giving the actual object itself
	std::cout << "Copy Constructor called of ClapTrap" << std::endl;
}

// Destructor: runs automatically when a ClapTrap goes out of scope
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator: runs on "a = b" when both already exist
ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	this->_name = assign._name;
	this->_hit_points = assign._hit_points;
	this->_energy_points = assign._energy_points;
	this->_attack_damage = assign._attack_damage;
	return *this;
}


//  public member functions

// causes the target to lose hit points equal to this ClapTrap's attack damage
// costs 1 energy point. Refuses to act if dead or out of energy.
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

// reduces hit points by "amount". If the incoming damage is enough to kill
// hit points are clamped to 0 instead of going negative
void ClapTrap::takeDamage(unsigned int amount)
{
	// Unsigned can't go negative
	// it wraps around to a huge number near UINT_MAX, 
	// a near-dead robot would look like it has billions of HP and never die.
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

// heals "amount" hit points. Like attack(), this also costs energy
// blocked if dead or out of energy.
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
