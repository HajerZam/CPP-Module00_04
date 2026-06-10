/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 21:02:29 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/10 14:45:12 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName() const
{
	return (_firstName);
}
std::string Contact::getLastName() const
{
	return (_lastName);
}
std::string Contact::getNickname() const
{
	return (_nickname);
}
std::string Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}
std::string Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}


void Contact::setFirstName(const std::string& value)
{
	_firstName = value;
}
void Contact::setLastName(const std::string& value)
{
	_lastName = value;
}
void Contact::setNickname(const std::string& value)
{
	_nickname = value;
}
void Contact::setPhoneNumber(const std::string& value)
{
	_phoneNumber = value;
}
void Contact::setDarkestSecret(const std::string& value)
{
	_darkestSecret = value;
}
