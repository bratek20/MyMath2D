#include <iostream>
#include <string>
#include "Point.h"
#include "Segment.h"
#include "Triangle.h"
#include "MyMath.h"

using namespace std;

void makeEnter() {
    cout << "\n";
}

template<class Shape>
void testTranslate(Shape shape) {
    makeEnter();

    cout << "Testing translation\n";
    cout << "Before translation: " << shape << "\n";

    double dx = rand() % 10;
    double dy = rand() % 10;
    shape.translate(dx, dy);

    cout << "After translation for Vector( " << dx << ", " << dy << " ):\n";
    cout << shape << "\n";
}

template<class Shape>
void testRotate(Shape shape) {
    makeEnter();

    cout << "Testing rotation\n";
    cout << "Before rotation: " << shape << "\n";

    double cx = rand() % 10;
    double cy = rand() % 10;
    double angle = rand() % 360;
    shape.rotate(cx, cy, angle);

    cout << "After rotation at Point( " << cx << ", " << cy << " ) for angle "<< angle<<":\n";
    cout << shape << "\n";
}

template<class Shape>
void testMiddlePoint(Shape& shape) {
    makeEnter();

    cout << "Testing middlePoint\n";
    cout << "For: " << shape << "\n";
    cout << "Middle Point: " << shape.middlePoint() << "\n";

    cout << "If contains middlePoint : " << shape.contains(shape.middlePoint()) << "\n";
}

void testPoint(Point& p) {
    makeEnter();
    
    cout << "Testing point: " << p << "\n";
    
    testTranslate(p);
    testRotate(p);
}

void testSegment(Segment& s) {
    cout << "Testing: " << s << "\n";

    testTranslate(s);
    testRotate(s);

    testMiddlePoint(s);

    cout << "Lenght: " << s.lenght() << "\n";
}

void testSegments(Segment& s1, Segment& s2) {
    makeEnter();

    cout << "Testing " << s1 << " " << s2 << "\n";
    cout << "Parallel? " << mm::areParallel(s1, s2) << "\n";
    cout << "Perpendicular? " << mm::arePerpendicular(s1, s2) << "\n";
    
    cout << "Intersects?" << mm::intersects(s1, s2) << "\n";
    if (mm::intersects(s1, s2)) {
        cout << "at Point: " << mm::intersectionPoint(s1, s2) <<"\n";
    }
}

void testTriangle(Triangle& t) {
    makeEnter();

    cout << "Testing: " << t << "\n";

    testTranslate(t);
    testRotate(t);

    testMiddlePoint(t);

    cout << "Perimeter: " << t.perimeter() << "\n";
    cout << "Area: " << t.area() << "\n";
}

void testTriangles(Triangle& t1, Triangle& t2) {
    makeEnter();

    cout << "If " << t1 << " contains " << t2 << "? " << mm::contains(t1, t2) << "\n";
    cout << "If " << t2 << " contains " << t1 << "? " << mm::contains(t1, t2) << "\n" ;
    cout << "If " << t1 << " and " << t2 << " are separable? " << mm::separable(t1, t2) << "\n";
}

int main() {
    try {
        Point p1(-1, 0);
        Point p2(1, 0);
        Point p3(0, 1);
        Point p4(0, -1);

        Segment s1(p1, p2);
        Segment s2(p3, p4);
        Triangle t1(p1, p2, p3);
        Triangle t2(p1, p2, p3);

        testPoint(p1);
        
        testSegment(s1);
        testSegments(s1, s2);
        
        testTriangle(t1);
        testTriangles(t1,t2);
    }
    catch (string error) {
        cerr << "Error: "<<error<<"\n";
    }

    return 0;
}