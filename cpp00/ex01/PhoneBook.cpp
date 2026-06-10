/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 21:05:16 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/10 14:06:54 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>
#include <cstdlib>

PhoneBook::PhoneBook() : _count(0), _oldest(0) {}

void PhoneBook::printColumn(std::string str) const
{
	if (str.size() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << str << "|";
}

void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	std::cout << "First name: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field can't be empty. First name: ";
	newContact.setFirstName(input);

	std::cout << "Last name: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field can't be empty. Last name: ";
	newContact.setLastName(input);

	std::cout << "Nickname: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field can't be empty. Nickname: ";
	newContact.setNickname(input);

	std::cout << "Phone number: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field can't be empty. Phone number: ";
	newContact.setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field can't be empty. Darkest secret: ";
	newContact.setDarkestSecret(input);

	_contacts[_oldest] = newContact;
	_oldest = (_oldest + 1) % 8;
	if (_count < 8)
		_count++;
}

void PhoneBook::searchContact() const
{
	if (_count == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}
	std::cout << "----------+----------+----------+----------+" << std::endl;
	printColumn("index");
	printColumn("first name");
	printColumn("last name");
	printColumn("nickname");
	std::cout << std::endl;
	std::cout << "----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::stringstream ss;
		ss << i;
		printColumn(ss.str());
		printColumn(_contacts[i].getFirstName());
		printColumn(_contacts[i].getLastName());
		printColumn(_contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "----------+----------+----------+----------+" << std::endl;
	std::string input;
	int index;
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	std::stringstream ss(input);
	if (input.empty() || !(ss >> index) || index < 0 || index >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << "First name:     " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name:      " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname:       " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number:   " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}
