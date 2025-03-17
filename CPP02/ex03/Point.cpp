#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point Point::operator=(const Point& dup)
{
    Point point(dup.x, dup.y);
    return point; 
}

Point::Point(const Point& other)
{
}

int Point::getX()
{
    return x;
}


int Point::getY()
{
    return y;
}