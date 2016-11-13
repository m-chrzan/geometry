#include "testing.h"
#include "geometry.h"
#include <iostream>

void positionPlusVector() {
    beginTest();

    Position p(3, 4);
    Vector v(23, -5);

    checkEqual<Position>(p + v, Position(26, -1), "Position + Vector ok.");
    checkEqual<Position>(v + p, Position(26, -1), "Vector + Position ok.");
    checkEqual<Position>(p, Position(3, 4), "Position unchanged");
    checkEqual<Vector>(v, Vector(23, -5), "Position unchanged");

    finishTest();
}

void vectorPlusVector() {
    beginTest();

    Vector v1(3, 4);
    Vector v2(23, -5);

    checkEqual<Vector>(v1 + v2, Vector(26, -1), "Vector + Vector ok.");
    checkEqual<Vector>(v2 + v1, Vector(26, -1), "Addition is commutative.");
    checkEqual<Vector>(v1, Vector(3, 4), "First vector unchanged.");
    checkEqual<Vector>(v2, Vector(23, -5), "Second vector unchanged.");

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
    checkEqual<Rectangle>(r, Rectangle(23, 43, Position(-10, 28)),
            "Rectangle unchanged.");
    checkEqual<Vector>(v, Vector(-42, 13), "Vector unchanged.");

    finishTest();
}

void rectanglesPlusVector() {
    beginTest();

    Rectangles rs = {Rectangle(12, 13), Rectangle(1, 2, Position(-1, -2)),
        Rectangle(2, 42, Position(55, 3))};
    Vector v(-1, 1);

    checkEqual<Rectangles>(rs + v,
                           Rectangles{Rectangle(12, 13, Position(-1, 1)),
                           Rectangle(1, 2, Position(-2, -1)),
                           Rectangle(2, 42, Position(54, 4))},
                           "Rectangles + Vector ok.");
    checkEqual<Rectangles>(v + rs,
                           Rectangles{Rectangle(12, 13, Position(-1, 1)),
                           Rectangle(1, 2, Position(-2, -1)),
                           Rectangle(2, 42, Position(54, 4))},
                           "Vector + Rectangles ok.");
    checkEqual<Rectangles>(rs,
                           Rectangles{Rectangle(12, 13),
                           Rectangle(1, 2, Position(-1, -2)),
                           Rectangle(2, 42, Position(55, 3))},
                           "Rectangles unchanged.");
    checkEqual<Vector>(v, Vector(-1, 1), "Vector unchanged.");

    finishTest();
}

void compoundAdditions() {
    beginTest();

    Position p(4, 2);
    Rectangle r(13, 7, p);
    Rectangles rs{r, Rectangle(1, 2)};

    Vector v1(0, 0), v2(-1, 1), v3(10, 20);

    checkEqual<Position>((v1 + p) + v2, Position(3, 3),
            "(Vector + Position) + Vector ok.");
    checkEqual<Position>((v1 + v2) + p, Position(3, 3),
            "(Vector + Vector) + Position ok.");
    checkEqual<Rectangle>(v2 + (v3 + r), Rectangle(13, 7, Position(13, 23)),
            "Vector + (Vector + Rectangle) ok.");
    checkEqual<Rectangle>(v2 + (r + v3), Rectangle(13, 7, Position(13, 23)),
            "Vector + (Rectangle + Vector) ok.");
    checkEqual<Rectangles>((rs + v1) + v3,
                           Rectangles{
                               Rectangle(13, 7, Position(14, 22)),
                               Rectangle(1, 2, Position(10, 20))
                           }, "(Rectangles + Vector) + Vector ok.");
    checkEqual<Rectangles>(rs + (v1 + v3),
                           Rectangles{
                               Rectangle(13, 7, Position(14, 22)),
                               Rectangle(1, 2, Position(10, 20))
                           }, "Rectangles + (Vector + Vector) ok.");

    checkEqual<Position>(p, Position(4, 2), "Position unchanged.");
    checkEqual<Rectangle>(r, Rectangle(13, 7, Position(4, 2)),
            "Rectangle unchanged.");
    checkEqual<Rectangles>(rs,
                           Rectangles{
                               Rectangle(13, 7, Position(4, 2)),
                               Rectangle(1, 2)
                           }, "Rectangles unchanged.");
    checkEqual<Vector>(v1, Vector(0, 0), "First Vector unchanged.");
    checkEqual<Vector>(v2, Vector(-1, 1), "Second Vector unchanged.");
    checkEqual<Vector>(v3, Vector(10, 20), "Third Vector unchanged.");


    finishTest();
}


int main() {
    positionPlusVector();
    vectorPlusVector();
    rectanglePlusVector();
    rectanglesPlusVector();
    compoundAdditions();
}
