#include "./includes/Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}
Point::Point(const Point &src) : _x(src._x), _y(src._y) {}
Point::~Point() {}
Point &Point::operator=(const Point &src) {
	if (this == &src)
		return *this;
	return *this;
}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }
