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

int main() {
    testRectangleConstructors();
    testRectangleEquality();
    testRectangleReflection();
}
