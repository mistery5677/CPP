#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point& Point::operator=(const Point& dup)
{
	(void)dup;
	return *this;
}

Point::Point(const Point& other) : x(other.x), y(other.y) {}


Point::~Point()
{
}
float Point::getX() const
{
    return x.toFloat();
}


float Point::getY() const
{
    return y.toFloat();
}