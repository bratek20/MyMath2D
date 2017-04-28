#include "MyMath.h"
#include "Point.h"
#include "Segment.h"
#include "Triangle.h"

bool mm::isZero(double value) {
    return abs(value) < EPSILON;
}

mm::LinearEq::LinearEq(const Point& p1, Point p2) {
    A = p1.getY() - p2.getY();
    B = p2.getX() - p1.getX();
    C = p1.getX()*p2.getY() - p2.getX()*p1.getY();
}

bool mm::LinearEq::fullfills(const Point& p) const {
    return isZero(A*p.getX() + B*p.getY() + C);
}

mm::Vector::Vector(const Point& p1, Point p2) {
    x = p2.getX() - p1.getX();
    y = p2.getY() - p1.getY();
}

double mm::distance(const Point& p1, const Point& p2) {
    double dx = p1.getX() - p2.getX();
    double dy = p1.getY() - p2.getY();
    
    return sqrt(dx*dx + dy*dy);
}

double mm::dotProduct(const Vector& v1, const Vector& v2) {
    return v1.x*v2.x + v1.y*v2.y;
}

double mm::crossProduct(const Vector& v1, const Vector& v2) {
    return v1.x*v2.y - v2.x*v1.y;
}

bool mm::areParallel(const Segment& s1, const Segment& s2) {
    Vector v1{ s1.getP1(), s1.getP2() };
    Vector v2{ s2.getP1(), s2.getP2() };
    
    return isZero(crossProduct(v1, v2));
}

bool mm::arePerpendicular(const Segment& s1, const Segment& s2) {
    Vector v1{ s1.getP1(), s1.getP2() };
    Vector v2{ s2.getP1(), s2.getP2() };

    return isZero(dotProduct(v1, v2));
}

Point mm::intersectionPoint(const Segment& s1, const Segment& s2) {
    if (areParallel(s1, s2))
        throw std::string("Segments are parallel!");

    LinearEq eq1{ s1.getP1(), s1.getP2() };
    LinearEq eq2{ s2.getP1(), s2.getP2() };

    double det = eq1.A*eq2.B - eq2.A*eq1.B;
    Point p = Point(-(eq2.B * eq1.C - eq1.B * eq2.C) / det, -(eq1.A * eq2.C - eq2.A * eq1.C) / det);
    
    if (!s1.contains(p) || !s2.contains(p))
        throw std::string("Segments are not intersecting!");
    return p;
}

bool mm::intersects(const Segment& s1, const Segment& s2) {
    try {
        intersectionPoint(s1, s2);
        return true;
    }
    catch (...) {
        return false;
    }
}

bool mm::contains(const Triangle& t1, const Triangle& t2) {
    return t1.contains(t2.getP1()) && t1.contains(t2.getP2()) && t1.contains(t2.getP3());
}

bool mm::contains(const Triangle& t, const Point& p) {
    return t.contains(p);
}

std::vector<Segment> mm::makeSegments(const Triangle& t) {
    std::vector<Segment> segments;
    segments.emplace_back(t.getP1(), t.getP2());
    segments.emplace_back(t.getP2(), t.getP3());
    segments.emplace_back(t.getP3(), t.getP1());

    return segments;
}

bool mm::separable(const Triangle& t1, const Triangle& t2) {
    if (contains(t1, t2) || contains(t2, t1)) 
        return false;
    
    auto segments1 = makeSegments(t1);
    auto segments2 = makeSegments(t2);

    for (auto& s1 : segments1)
        for (auto& s2 : segments2)
            if (intersects(s1, s2))
                return false;
    
    return true;
}