#include "Segment.h"
#include "MyMath.h"
#include <algorithm>

Segment::Segment(Point p1, Point p2) : p1(p1), p2(p2) {
    if(mm::isZero(p1.getX() - p2.getX()) &&
       mm::isZero(p1.getY() - p2.getY()) ) 
       throw std::string("Points must be different!");
}

Segment::Segment(const Segment& seg) {
    p1 = seg.p1;
    p2 = seg.p2;
}

Segment& Segment::operator=(const Segment& seg) {
    p1 = seg.p1;
    p2 = seg.p2;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Segment& seg) {
    out << "Segment[ " << seg.p1 << " ; " << seg.p2 << " ]";
    return out;
}

void Segment::translate(double dx, double dy){
    p1.translate(dx, dy);
    p2.translate(dx, dy);
}

void Segment::rotate(double centerX, double centerY, double angle){
    p1.rotate(centerX, centerY, angle);
    p2.rotate(centerX, centerY, angle);
}

double Segment::lenght() const {
    return mm::distance(p1, p2);
}

bool Segment::contains(const Point& p) const {
    mm::LinearEq eq{ p1, p2 };

    return eq.fullfills(p) && 
           std::min(p1.getX(), p2.getX()) <= p.getX() &&
           std::max(p1.getX(), p2.getX()) >= p.getX();
}

Point Segment::middlePoint() const {
    double mx = (p1.getX() + p2.getX())/2;
    double my = (p1.getY() + p2.getY()) / 2;

    return Point(mx, my);
}