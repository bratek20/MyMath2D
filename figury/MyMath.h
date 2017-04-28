#ifndef MY_MATH_H
#define MY_MATH_H

#include<vector>

class Point;
class Segment;
class Triangle;

namespace mm {
    const double EPSILON = 1e-9;
    bool isZero(double value);

    struct LinearEq {
        double A, B, C;

        LinearEq(const Point& p1, Point p2);

        bool fullfills(const Point& p) const;
    };

    struct Vector {
        double x, y;

        Vector(const Point& p1, Point p2);
    };

    double distance(const Point& p1, const Point& p2);
    double dotProduct(const Vector& v1, const Vector& v2);
    double crossProduct(const Vector& v1, const Vector& v2);

    bool areParallel(const Segment& s1, const Segment& s2);
    bool arePerpendicular(const Segment& s1, const Segment& s2);
    Point intersectionPoint(const Segment& s1, const Segment& s2);
    bool intersects(const Segment& s1, const Segment& s2);

    bool contains(const Triangle& t1, const Triangle& t2);
    bool contains(const Triangle& t, const Point& p);
    std::vector<Segment> makeSegments(const Triangle& t);
    bool separable(const Triangle& t1, const Triangle& t2);
    
}

#endif // !MY_MATH_H

