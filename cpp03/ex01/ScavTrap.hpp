#pragma once
#include "ClapTrap.hpp"

// ScavTrap is a ClapTrap's child! a derived class from it
// it gets all of attributes and methods!
class ScavTrap : public ClapTrap {
    public:
        // Even though ScavTrap inherits ClapTrap's constructor logic IN THEORY (A GAME THEORY)
        // C++ does NOT auto-inherit constructors
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &assign);

        // attack() is redeclared here to OVERRIDE ClapTrap::attack()
        // Any ScavTrap object calling .attack() will use this version, not the base class one
        void    attack(const std::string &target);
        void    guardGate();
};
