/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:35:02 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/19 13:01:57 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// initializer list is used to initialize the _type member variable with the type argument
Weapon::Weapon(std::string type) : _type(type)
{
}

// member function to get the type of the weapon
const std::string& Weapon::getType() const
{
	return (_type);
}
// member function to set the type of the weapon
void Weapon::setType(std::string type)
{
	_type = type;
}
