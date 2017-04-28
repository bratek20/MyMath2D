#include "Point.h"
#include <cmath>
#define M_PI 3.14159265358979323846

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point& p) {
    x = p.x;
    y = p.y;
}

Point& Point::operator=(const Point& p) {
    x = p.x;
    y = p.y;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << std::fixed << "(" << p.x << " , " << p.y << ")";
    return out;
}

void Point::translate(double dx, double dy){
    x += dx;
    y += dy;
}

void Point::rotate(double centerX, double centerY, double angle) {
    angle = angle / 180 * M_PI;
    double vx = x - centerX;
    double vy = y - centerY;

    double dx = vx*cos(angle) - vy*sin(angle);
    double dy = vx*sin(angle) + vy*cos(angle);

    x = centerX + dx;
    y = centerY + dy;
}