/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:34:21 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/19 13:00:07 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// constructor and destructor
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
}

// member function
void HumanA::attack() const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
