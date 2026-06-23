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

        // comparison operators: public overloaded member functions
        // static member function that takes two references to Fixed-point numbers and returns a ref to smallest
        static Fixed &min(Fixed &a, Fixed &b);
        // static member function that takes two references to const Fixed-point numbers and returns a ref to smallest
        static const Fixed &min(const Fixed &a, const Fixed &b);
        // static member function that takes two references to Fixed-point numbers and returns a ref to largest
        static Fixed &max(Fixed &a, Fixed &b);
        // static member function that takes two references to const Fixed-point numbers and returns a ref to largest
        static const Fixed &max(const Fixed &a, const Fixed &b);

        // arithmetic operators: public overloaded member functions
        // comparison operators
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        // arithmetic operators
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        // increment/decrement
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
