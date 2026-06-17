/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:43:58 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/17 11:50:46 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* Horde = zombieHorde(5, "Zombie");

	for (int i = 0; i < 5; i++)
	{
		Horde[i].announce();
	}
	delete[] Horde;
	return (0);
}