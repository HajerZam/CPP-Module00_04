/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:37:04 by halzamma          #+#    #+#             */
/*   Updated: 2026/06/22 21:37:04 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor - sets _fixedPointValue to 0, prints message
Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other.getRawBits();
    return *this;
}

// getRawBits: returns the raw fixed-point value
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

// setRawBits: sets the raw fixed-point value
void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

// new addition

// constructor that takes a const int and converts it to fixed-point representation
Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

// constructor that takes a const floating-point number and converts it to the fixed-point value
Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

// toFloat: divide _fixedPointValue by 2^8
float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}
// toInt: shift right by 8 bits
int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

// Overload the insertion operator for Fixed class
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}