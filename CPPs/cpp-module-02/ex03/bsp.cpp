#include "./includes/Fixed.hpp"
#include "./includes/Point.hpp"
#include "iostream"

float getAbsoluteValue(float value)
{
    if (value < 0) 
        return -value;
    return value;
}

float calculateArea(Point const a, Point const b, Point const c)
{
    return getAbsoluteValue(a.getX() * (b.getY() - c.getY()) + 
                            b.getX() * (c.getY() - a.getY()) + 
                            c.getX() * (a.getY() - b.getY())) / 2.0f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float areaABC = calculateArea(a, b, c);

    float areaPAB = calculateArea(point, a, b);
    float areaPAC = calculateArea(point, a, c);
    float areaPCB = calculateArea(point, b, c);

    if (areaPAB == 0 || areaPAC == 0 || areaPCB == 0)
        return false;

    return areaABC == areaPAB + areaPAC + areaPCB;
}
