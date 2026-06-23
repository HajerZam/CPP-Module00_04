#pragma once

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
    public:
        Fixed(); // Default constructor
        Fixed(const Fixed &other); // Copy constructor
        Fixed &operator=(const Fixed &other); // Copy assignment operator
        ~Fixed(); // Destructor

        Fixed(const int value); // Int constructor
        Fixed(const float value); // Float constructor
        float   toFloat(void) const; // Converts fixed-point to float
        int     toInt(void) const; // Converts fixed-point to int
    
        int     getRawBits(void) const; // Getter for the raw fixed-point value
        void    setRawBits(int const raw); // Setter for the raw fixed-point value
};