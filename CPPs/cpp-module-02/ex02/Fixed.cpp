#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}
Fixed::Fixed(const int number) {
    _value = number << _fractionalBits;
}
Fixed::Fixed(const float fnumber) {
    _value = roundf(fnumber * (1 << _fractionalBits));
}
Fixed::Fixed(const Fixed &src) {
    *this = src;
}
Fixed::~Fixed() {}

// ================ Operators Overload =============>
Fixed &Fixed::operator=(const Fixed &src)
{
	this->_value = src._value;
	return *this;
}

// ================ comparison operators =============>
bool Fixed::operator<(Fixed other) const
{
	return (this->_value < other._value);
}
bool Fixed::operator<=(Fixed other) const
{
	return (this->_value <= other._value);
}
bool Fixed::operator>(Fixed other) const
{
	return (this->_value > other._value);
}
bool Fixed::operator>=(Fixed other) const
{
	return (this->_value >= other._value);
}
bool Fixed::operator==(Fixed other) const
{
	return (this->_value == other._value);
}
bool Fixed::operator!=(Fixed other) const
{
	return (this->_value != other._value);
}

// ================ arithmetic operators =============>
float Fixed::operator+(Fixed other) const
{
	return (this->toFloat() + other.toFloat());
}
float Fixed::operator-(Fixed other) const
{
	return (this->toFloat() - other.toFloat());
}
float Fixed::operator*(Fixed other) const
{
	return (this->toFloat() * other.toFloat());
}
float Fixed::operator/(Fixed other) const
{
	return (this->toFloat() / other.toFloat());
}

// ================ inc/dec operators =============>
Fixed Fixed::operator++()
{
	this->_value++;
	return *this;
}
Fixed Fixed::operator--()
{
	this->_value--;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// ================ Member functions =============>
int Fixed::getRawBits(void) const
{
	return this->_value;
}
void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->_fractionalBits);
}
int Fixed::toInt(void) const
{
	return this->_value >> this->_fractionalBits;
}

// ================ Min/Max =============>
Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	return (first < second ? first : second);
}
const Fixed &Fixed::min(Fixed const &first, Fixed const &second)
{
	return (first < second ? first : second);
}
Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	return (first > second ? first : second);
}
const Fixed &Fixed::max(Fixed const &first, const Fixed &second)
{
	return (first > second ? first : second);
}

// ================ Overload for ostream =================>
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
