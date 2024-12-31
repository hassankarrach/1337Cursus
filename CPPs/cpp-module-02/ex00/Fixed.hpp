#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int _value;
        static const int _fractionalBits;

    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed); // copy assignment operator
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif