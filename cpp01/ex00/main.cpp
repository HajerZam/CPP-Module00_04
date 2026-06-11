/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:22:32 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/11 13:54:17 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie *oneZombie;

	oneZombie = newZombie("sticky");
	oneZombie->announce();
	randomChump("spooky");
	delete oneZombie;
}