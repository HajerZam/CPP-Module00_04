/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:34:17 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/19 13:00:07 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// constructor and destructor
HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}


// member function : reference to weapon is passed to the function
// the pointer is set to point to that weapon beacause the weapon is passed by reference, so it will not be destroyed when the function ends
void    HumanB::attack() const
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
