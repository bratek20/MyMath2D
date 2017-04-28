#include "Triangle.h"
#include "MyMath.h"

Triangle::Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {
    if (mm::isZero(area()))
        throw std::string("Points must construct triangle!");
}

Triangle::Triangle(const Triangle& tri) {
    p1 = tri.p1;
    p2 = tri.p2;
    p3 = tri.p3;
}

Triangle& Triangle::operator=(const Triangle& tri) {
    p1 = tri.p1;
    p2 = tri.p2;
    p3 = tri.p3;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Triangle& tri) {
    out << "Triangle< " << tri.p1 << " ; " << tri.p2 << " ; " << tri.p3 << " >";
    return out;
}

void Triangle::translate(double dx, double dy){
    p1.translate(dx, dy);
    p2.translate(dx, dy);
    p3.translate(dx, dy);
}

void Triangle::rotate(double centerX, double centerY, double angle){
    p1.rotate(centerX, centerY, angle);
    p2.rotate(centerX, centerY, angle);
    p3.rotate(centerX, centerY, angle);
}

Point Triangle::middlePoint() const {
    double mx = (p1.getX() + p2.getX() + p3.getX()) / 3;
    double my = (p1.getY() + p2.getY() + p3.getY()) / 3;

    return Point(mx, my);
}

double Triangle::perimeter() const {
    return mm::distance(p1, p2) + mm::distance(p2, p3) + mm::distance(p3, p1);
}

double Triangle::area(const Point& p1, const Point& p2, const Point& p3) const {
    return abs( mm::crossProduct(mm::Vector(p1, p2), mm::Vector(p1, p3)) )/ 2;
}

double Triangle::area() const {
    return area(p1, p2, p3);
}

bool Triangle::contains(const Point& p) const {
    return mm::isZero( area(p1, p2, p) + area(p2, p3, p) + area(p3, p1, p) - area() );
}