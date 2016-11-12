#include "testing.h"
#include "geometry.h"

void testRectangleConstructors() {
    beginTest();

    Rectangle r(2, 5, Position(-1, 3));
    checkEqual<long long>(r.width(), 2, "Set width correctly.");
    checkEqual<long long>(r.height(), 5, "Set height correctly.");
    checkEqual<Position>(r.pos(), Position(-1, 3), "Set position correctly.");

    Rectangle s(r);
    checkEqual<long long>(s.width(), 2, "Set width correctly.");
    checkEqual<long long>(s.height(), 5, "Set height correctly.");
    checkEqual<Position>(s.pos(), Position(-1, 3), "Set position correctly.");

    Rectangle t(3, 6, Position(0, 4));
    t = Rectangle(2, 5, Position(-1, 3));
    checkEqual<long long>(s.width(), 2, "Set width correctly.");
    checkEqual<long long>(s.height(), 5, "Set height correctly.");
    checkEqual<Position>(s.pos(), Position(-1, 3), "Set position correctly.");

    Rectangle u(10, 20);
    checkEqual<long long>(u.width(), 10, "Set width correctly.");
    checkEqual<long long>(u.height(), 20, "Set height correctly.");
    checkEqual<Position>(u.pos(), Position::origin(), "Set position correctly.");

    finishTest();
}

void testRectangleEquality() {
    Rectangle r(42, -24, Position(0, 0));
    Rectangle r2(r);
    Rectangle s(42, -24, Position::origin());
    Rectangle t(42, -24);

    checkEqual<Rectangle>(r, r, "A Rectangle is equal to itself.");
    checkEqual<Rectangle>(r, r2, "A Rectangle is equal to its copy.");
    checkEqual<Rectangle>(r, s,
        "Rectangles initialized with equivalent values are equivalent.");

    Rectangle u(42, -23, Position(0, 0));
    Rectangle v(43, -24, Position(0, 0));
    Rectangle w(42, -24, Position(1, -1));
    checkNotEqual<Rectangle>(r, u, "Not equal if different height.");
    checkNotEqual<Rectangle>(r, v, "Not equal if different width.");
    checkNotEqual<Rectangle>(r, w, "Not equal if different position.");

    finishTest();
}

void testRectangleReflection() {
    beginTest();

    Rectangle r(3, 4, Position(2, 3));
    Rectangle s = r.reflection();

    checkEqual<long long>(s.width(), 4, "Width set correctly.");
    checkEqual<long long>(s.height(), 3, "Height set correctly.");
    checkEqual<Position>(s.pos(), Position(3, 2), "Position set correctly.");

    Rectangle t = Rectangle(12, 2, Position(-5, -5)).reflection();
    checkEqual<Position>(t.pos(), Position(-5, -5),
        "Rectangle on x = y doesn't change position.");

    Rectangle sq(1009, 1009, Position(42, 42));
    checkEqual<Rectangle>(sq, sq.reflection(),
        "Square on x = y doesn't change.");

    finishTest();
}

void testRectangleArea() {
    beginTest();

    Rectangle r(7, 6);
    checkEqual<long long>(r.area(), 42, "Correctly calculates area");
    checkEqual<long long>(r.area(), r.reflection().area(),
        "Reflected Rectangle has the same area.");

    Rectangle s(0, 5);
    Rectangle t(5, 0);
    checkEqual<long long>(s.area(), 0, "Rectangle with no width has 0 area.");
    checkEqual<long long>(t.area(), 0, "Rectangle with no height has 0 area.");

    finishTest();
}

void testRectangleMoveByVector() {
    beginTest();

    Rectangle r(7, 6);
    Vector v(1, 1);
    r += v;
    checkEqual<long long>(r.width(), 7, "Width unchanged.");
    checkEqual<long long>(r.height(), 6, "Height unchanged.");
    checkEqual<long long>(r.pos().x(), 1, "Rectangle x coordinate moved correctly.");
    checkEqual<long long>(r.pos().y(), 1, "Rectangle y coordinate moved correctly.");

    Rectangle p(3, 5, Position(20, -5));
    Vector w(-20, 10);
    p += w;
    checkEqual<long long>(p.width(), 3, "Width unchanged.");
    checkEqual<long long>(p.height(), 5, "Height unchanged.");
    checkEqual<long long>(p.pos().x(), 0, "Rectangle x coordinate moved correctly.");
    checkEqual<long long>(p.pos().y(), 5, "Rectangle y coordinate moved correctly.");

    finishTest();
}

void testRectangleSplit() {
    beginTest();

    Rectangle r(7, 6);
    std::pair<Rectangle, Rectangle> rSplitHorizontally = r.split_horizontally(1);
    checkEqual<long long>(rSplitHorizontally.first.height(), 1,
                          "Height of lower rectangle correct.");
    checkEqual<long long>(rSplitHorizontally.second.height(), 6 - 1,
                          "Height of upper rectangle correct.");
    checkEqual<long long>(rSplitHorizontally.first.width(), 7,
                          "Width of lower rectangle unchanged.");
    checkEqual<long long>(rSplitHorizontally.second.width(), 7,
                          "Width of upper rectangle unchanged.");
    checkEqual<Position>(rSplitHorizontally.first.pos(), r.pos(),
                         "Position of lower rectangle same as original.");
    checkEqual<Position>(rSplitHorizontally.second.pos(), Position(0, 1),
                         "Position of lower rectangle higher than original.");

    std::pair<Rectangle, Rectangle> rSplitVertically = r.split_vertically(1);
    checkEqual<long long>(rSplitVertically.first.width(), 1,
                          "Width of left rectangle correct.");
    checkEqual<long long>(rSplitVertically.second.width(), 7 - 1,
                          "Width of right rectangle correct");
    checkEqual<long long>(rSplitVertically.first.height(), 6,
                          "Height of left rectangle correct.");
    checkEqual<long long>(rSplitVertically.second.height(), 6,
                          "Height of right rectangle correct");
    checkEqual<Position>(rSplitVertically.first.pos(), r.pos(),
                         "Position of left rectangle same as original.");
    checkEqual<Position>(rSplitVertically.second.pos(), Position(1, 0),
                         "Position of right rectangle further right than original.");

    finishTest();
}

int main() {
    testRectangleConstructors();
    testRectangleEquality();
    testRectangleReflection();
    testRectangleArea();
    testRectangleMoveByVector();
    testRectangleSplit();
}
