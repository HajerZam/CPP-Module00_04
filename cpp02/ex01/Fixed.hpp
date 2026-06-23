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
        ~Fixed(); // Destructor

        Fixed &operator=(const Fixed &other); // Copy assignment operator

        int     getRawBits(void) const; // Getter for the raw fixed-point value
        void    setRawBits(int const raw); // Setter for the raw fixed-point value

        // new addition
        // constructor that takes a const int and converts it to fixed-point representation
        Fixed(const int value);
        // constructor that takes a const floating-point number and converts it to the fixed-point value
        Fixed(const float value);
        // member function that converts the fixed-point value to a floating-point number
        float toFloat(void) const;
        // member function that converts the fixed-point value to an integer
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
