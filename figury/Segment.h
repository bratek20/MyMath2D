#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"

class Segment {
public:
    Segment(Point p1, Point p2);
    Segment(const Segment& seg);
    Segment& operator=(const Segment& seg);
    friend std::ostream& operator<<(std::ostream&, const Segment&);

    void translate(double dx, double dy);
    void rotate(double centerX, double centerY, double angle);

    double lenght() const;
    bool contains(const Point& p) const;
    Point middlePoint() const;

    const Point& getP1() const { return p1; }
    const Point& getP2() const { return p2; }

private:
    Point p1, p2;
};
#endif
