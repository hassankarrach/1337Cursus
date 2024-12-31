#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    // Constructors
    Fixed();
    Fixed(const int number);
    Fixed(const float fnumber);
    Fixed(const Fixed &src);
    // Destructor
    ~Fixed();

    // ==== Operators Overload
    Fixed &operator=(const Fixed &src);

    // ==== comparison operators ========>
    bool operator<(Fixed other) const;
    bool operator<=(Fixed other) const;
    bool operator>(Fixed other) const;
    bool operator>=(Fixed other) const;
    bool operator==(Fixed other) const;
    bool operator!=(Fixed other) const;
    // ==== arithmetic operators ========>
    float operator+(Fixed other) const;
    float operator-(Fixed other) const;
    float operator*(Fixed other) const;
    float operator/(Fixed other) const;
    // ==== inc/dec operators ===========>
    Fixed operator++();
    Fixed operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    // ==== Min/Max
    static Fixed &min(Fixed &first, Fixed &second);
    static const Fixed &min(Fixed const &first, Fixed const &second);
    static Fixed &max(Fixed &first, Fixed &second);
    static const Fixed &max(Fixed const &first, const Fixed &second);
};

// Overload for ostream
std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif