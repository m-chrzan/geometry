#include "geometry.h"
#include "testing.h"
#include <iostream>

void testPositionConstructors() {
    beginTest();

    Position p(3, 4);
    checkEqual<long>(p.x(), 3, "x-coordinate set correctly");
    checkEqual<long>(p.y(), 4, "y-coordinate set correctly");

    Position q(p);
    checkEqual<long>(q.x(), 3, "x-coordinate set correctly");
    checkEqual<long>(q.y(), 4, "y-coordinate set correctly");

    Position r(Position(3, 4));
    checkEqual<long>(r.x(), 3, "x-coordinate set correctly");
    checkEqual<long>(r.y(), 4, "y-coordinate set correctly");

    finishTest();
}

void testOrigin() {
    beginTest();

    checkEqual<long>(Position::origin().x(), 0, "x-coordinate is 0");
    checkEqual<long>(Position::origin().y(), 0, "y-coordinate is 0");

    finishTest();
}

void testPositionEquality() {
    beginTest();

    Position p(42, 0);
    Position p2(p);
    Position q(42, 0);
    checkEqual<Position>(p, p, "A Position is equal to itself.");
    checkEqual<Position>(p, p2, 
            "Copy constructor creates equivalent Position.");
    checkEqual<Position>(p, q, 
            "Positions initialized with same values are equal.");
    checkEqual<Position>(p, Position(42, 0), "Works with rvalues.");

    Position r(43, 0);
    checkNotEqual<Position>(p, r, 
            "Positions with different coordinates are not equivalent.");

    Position o(0, 0);
    checkEqual<Position>(o, Position::origin(), "Origin is equal to (0, 0)");

    finishTest();
}

void testPositionReflection() {
    beginTest();

    Position p(23, -5);
    Position r = p.reflection();
    checkEqual<long>(r.x(), -5, "x-coordinate set correctly.");
    checkEqual<long>(r.y(), 23, "x-coordinate set correctly.");

    Position q(42, 42);
    checkEqual<Position>(q, q.reflection(), 
            "Positions on x = y are fixed points.");

    checkEqual<Position>(Position::origin(), Position::origin().reflection(),
            "The origin is its own reflection");

    finishTest();
}

int main() {
    testPositionConstructors();
    testOrigin();
    testPositionEquality();
    testPositionReflection();

    return 0;
}
