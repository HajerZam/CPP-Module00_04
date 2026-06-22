/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:22:32 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/19 12:47:05 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie *oneZombie;

	// heap to outlive the scope of main, 
	// so we can call announce() after creating the zombie
	oneZombie = newZombie("sticky");
	oneZombie->announce();

	// create a temporary zombie that will announce itself 
	// and then be destroyed
	randomChump("spooky");
	delete oneZombie;
}