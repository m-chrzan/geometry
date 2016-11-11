#include "testing.h"
#include "geometry.h"

void testRectanglesConstructors() {
    beginTest();

    Rectangle r1(2, 5);
    Rectangle r2(2, 5);
    Rectangle r3(2, 5);
    Rectangles r({r1, r2, r3});
    checkEqual<long long>(r.size(), 3, "Set size correctly.");

    Rectangles emptyR;
    checkEqual<long long>(emptyR.size(), 0, "Size of an empty Rectangles is zero.");

    finishTest();
}

void testRectanglesGetRectangle() {
    beginTest();

    Rectangle r1(2, 5);
    Rectangle r2(2, 5);
    Rectangle r3(2, 5);
    Rectangles r({r1, r2, r3});
    checkEqual<Rectangle>(r[1], r1, "Operator Rectangles[] returns correct object.");

    finishTest();
}

void testRectanglesEquality() {
    beginTest();

    Rectangle r1(2, 5);
    Rectangle r2(1, 5);
    Rectangle r3(2, 5);
    Rectangle r4(1, 5);
    Rectangles rects1({r1, r2});
    Rectangles rects2({r3, r4});
    Rectangles rects3({r3, r3});
    checkEqual<Rectangles>(rects1, rects1, "Rectangles object is equal to itself.");
    checkEqual<Rectangles>(rects1, rects2, "Rectangles consisting of rectangles that are equal are equal.");
    checkNotEqual<Rectangles>(rects1, rects3, "Rectangles consisting of different rectangles are not equal.");
    checkNotEqual<Rectangles>(Rectangles(), rects3, "Rectangles with different sizes do not equal.");

    finishTest();
}

void testRectanglesMoveByVector() {
    beginTest();

    Rectangles r({Rectangle(1,1), Rectangle(2,2)});
    Vector v(1, 1);
    r += v;
    checkEqual<long long>(r[0].pos().x(), 1, "Rectangles first element was moved by vector.");
    checkEqual<long long>(r[1].pos().x(), 1, "Rectangles second element was moved by vector.");

    finishTest();
}

void testRectanglesSplit() {
    beginTest();

    Rectangle r1(2, 10);
    Rectangle r2(2, 20);
    Rectangle r3(2, 30);
    Rectangles r({r1, r2, r3});
    r.split_horizontally(1, 1);

    checkEqual<long long>(r.size(), 4, "Rectangles size increased with splitting.");
    checkEqual<Rectangle>(r[1], r2.split_horizontally(1).first,
                          "First rectangle from the split is correct.");
    checkEqual<Rectangle>(r[2], r2.split_horizontally(1).second,
                          "Second rectangle from the split is correct.");

    finishTest();
}

int main() {
    testRectanglesConstructors();
    testRectanglesGetRectangle();
    testRectanglesEquality();
    testRectanglesMoveByVector();
    testRectanglesSplit();
}

