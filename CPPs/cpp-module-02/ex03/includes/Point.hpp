#ifndef POINT_CPP
#define POINT_CPP

#include <cmath>
#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &src);
		~Point();
		Point &operator=(const Point &src);

		Fixed getX() const;
		Fixed getY() const;
};



#endif