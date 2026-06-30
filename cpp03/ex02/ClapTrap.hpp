#pragma once

# include <iostream>
# include <string>

// Base class of the inheritance chain.
// ScavTrap, FragTrap will all inherit from this.
class ClapTrap {
    protected:
        // could touch them, and derived classes would be forced to use
        // public getters/setters instead.
        std::string _name;
        int _hit_points;
        int _energy_points;
        int _attack_damage;
        // Helper functions, also protected so derived classes can reuse
        // same alive/energy checks instead of rewriting
        bool    haveEnergy();
        bool    isAlive();
    public:
    // Public interface — anyone holding a ClapTrap (or a ScavTrap/
    // FragTrap treated as a ClapTrap) can call these.
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
    // Orthodox Canonical Form 
        ClapTrap(std::string name); // constructor
	    ClapTrap(const ClapTrap &copy); // copy constructor
	    ~ClapTrap(); // destructor
	    ClapTrap &operator=(const ClapTrap &assign); // copy assignment
};
