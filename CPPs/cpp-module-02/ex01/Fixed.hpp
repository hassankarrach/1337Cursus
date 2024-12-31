#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int _value;
        static const int _fractionalBits;
    
    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float fnumber);
        Fixed(const Fixed &src);
        ~Fixed();
        Fixed &operator=(const Fixed &src);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif