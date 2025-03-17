#pragma  once

class Point
{
private:
    const int x;
    const int y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    Point operator=(const Point& other);
    ~Point();
};