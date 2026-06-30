#pragma once
#include "ClapTrap.hpp"

// FragTrap, like ScavTrap, publicly inherits from ClapTrap
class FragTrap : public ClapTrap {
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &assign);

        // Overrides ClapTrap::attack() with FragTrap own stats
        void    attack(const std::string &target);
        void    highFivesGuys(void);
};
