#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point {
public:
    Point() {}
    Point(double x, double y);
    Point(const Point& p);
    Point& operator=(const Point& p);
    friend std::ostream& operator<<(std::ostream&, const Point&);

    void translate(double dx, double dy);
    void rotate(double centerX, double centerY, double angle);

    double getX() const { return x; }
    double getY() const { return y; }

private:
    double x = 0;
    double y = 0;
};

#endif
