#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{
	private:
		std::string name;
	public:
		Zombie(std::string name);	// constructor with name parameter
		Zombie();	// default constructor
		~Zombie();	// destructor
		void announce( void );	// method to announce the zombie's name

};

#endif