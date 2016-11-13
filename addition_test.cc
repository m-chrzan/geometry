#include "testing.h"
#include "geometry.h"
#include <iostream>

void positionPlusVector() {
    beginTest();

    Position p(3, 4);
    Vector v(23, -5);

    checkEqual<Position>(p + v, Position(26, -1), "Position + Vector ok.");
    checkEqual<Position>(v + p, Position(26, -1), "Vector + Position ok.");

    finishTest();
}

void vectorPlusVector() {
    beginTest();

    Vector v1(3, 4);
    Vector v2(23, -5);

    checkEqual<Vector>(v1 + v2, Vector(26, -1), "Vector + Vector ok.");
    checkEqual<Vector>(v2 + v1, Vector(26, -1), "Addition is commutative.");

    finishTest();
}

void rectanglePlusVector() {
    beginTest();

    Rectangle r(23, 43, Position(-10, 28));
    Vector v(-42, 13);

    checkEqual<Rectangle>(r + v, Rectangle(23, 43, Position(-52, 41)),
            "Rectangle + Vector ok.");
    checkEqual<Rectangle>(v + r, Rectangle(23, 43, Position(-52, 41)),
            "Vector + Rectangle ok.");

    finishTest();
}

void rectanglesPlusVector() {
    beginTest();

    Rectangles rs = {Rectangle(12, 13), Rectangle(1, 2, Position(-1, -2)),
        Rectangle(-2, 42, Position(55, 3))};
    Vector v(-1, 1);

    checkEqual<Rectangles>(rs + v,
                           Rectangles{Rectangle(12, 13, Position(-1, 1)),
                           Rectangle(1, 2, Position(-2, -1)),
                           Rectangle(-2, 42, Position(54, 4))},
                           "Rectangles + Vector ok.");
    checkEqual<Rectangles>(v + rs,
                           Rectangles{Rectangle(12, 13, Position(-1, 1)),
                           Rectangle(1, 2, Position(-2, -1)),
                           Rectangle(-2, 42, Position(54, 4))},
                           "Vector + Rectangles ok.");

    finishTest();
}

int main() {
    positionPlusVector();
    vectorPlusVector();
    rectanglePlusVector();
    rectanglesPlusVector();
}
