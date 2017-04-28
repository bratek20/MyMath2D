#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
public:
    Triangle(Point p1, Point p2, Point p3);
    Triangle(const Triangle& tri);
    Triangle& operator=(const Triangle& tri);
    friend std::ostream& operator<<(std::ostream&, const Triangle&);

    void translate(double dx, double dy);
    void rotate(double centerX, double centerY, double angle);

    Point middlePoint() const;
    double perimeter() const;
    double area() const;
    bool contains(const Point& p) const;

    const Point& getP1() const { return p1; }
    const Point& getP2() const { return p2; }
    const Point& getP3() const { return p3; }

private:
    double area(const Point& p1, const Point& p2, const Point& p3) const;
    Point p1, p2, p3;
};

#endif
