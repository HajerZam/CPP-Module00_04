#pragma once

# include <iostream>
# include <string>

class ClapTrap {
    private:
        std::string _name;
        int _hit_points;
        int _energy_points;
        int _attack_damage;

        bool    haveEnergy();
        bool    isAlive();
    public:
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        ClapTrap(std::string name);
	    ClapTrap(const ClapTrap &copy);
	    ~ClapTrap();
	    ClapTrap &operator=(const ClapTrap &assign);
};
