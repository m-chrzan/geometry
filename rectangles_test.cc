#include "testing.h"
#include "geometry.h"

void testRectanglesConstructors() {
    beginTest();

    Rectangle r1(2, 5);
    Rectangle r2(2, 5);
    Rectangle r3(2, 5);
    Rectangles r({r1, r2, r3});
    checkEqual<int32_t>(r.size(), 3, "Set size correctly.");
    checkEqual<Rectangle>(r[0], r1, "First Rectangle correct.");
    checkEqual<Rectangle>(r[1], r2, "First Rectangle correct.");
    checkEqual<Rectangle>(r[2], r3, "First Rectangle correct.");

    Rectangles emptyR;
    checkEqual<int32_t>(emptyR.size(), 0, "Size of an empty Rectangles is zero.");

    Rectangles copy(r);
    checkEqual<int32_t>(copy.size(), 3, "Set size correctly.");
    checkEqual<Rectangle>(copy[0], r1, "First Rectangle correct.");
    checkEqual<Rectangle>(copy[1], r2, "First Rectangle correct.");
    checkEqual<Rectangle>(copy[2], r3, "First Rectangle correct.");

    Rectangles move(std::move(Rectangles { r1, r2, r3 }));
    checkEqual<int32_t>(move.size(), 3, "Set size correctly.");
    checkEqual<Rectangle>(move[0], r1, "First Rectangle correct.");
    checkEqual<Rectangle>(move[1], r2, "First Rectangle correct.");
    checkEqual<Rectangle>(move[2], r3, "First Rectangle correct.");

    finishTest();
}

void testRectanglesGetRectangle() {
    beginTest();

    Rectangle r1(2, 5);
    Rectangle r2(3, 5, Position(-3, 6));
    Rectangle r3(42, 5);
    Rectangles r({r1, r2, r3});
    checkEqual<Rectangle>(r[0], r1,
                          "Operator Rectangles[] returns correct object.");
    checkEqual<Rectangle>(r[1], r2,
                          "Operator Rectangles[] returns correct object.");
    checkEqual<Rectangle>(r[2], r3,
                          "Operator Rectangles[] returns correct object.");

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
    checkEqual<Rectangles>(rects1, rects1,
                           "Rectangles object is equal to itself.");
    checkEqual<Rectangles>(rects1, rects2,
                           "Rectangles consisting of rectangles that are equal are equal.");
    checkNotEqual<Rectangles>(rects1, rects3,
                              "Rectangles consisting of different rectangles are not equal.");
    checkNotEqual<Rectangles>(Rectangles(), rects3,
                              "Rectangles with different sizes do not equal.");

    finishTest();
}

void testRectanglesMoveByVector() {
    beginTest();

    Rectangles r({Rectangle(1, 1), Rectangle(2, 2)});
    Vector v(1, 1);
    r += v;
    checkEqual<int32_t>(r[0].pos().x(), 1, "Rectangles first element was moved "
            "by vector.");
    checkEqual<int32_t>(r[1].pos().x(), 1, "Rectangles second element was moved "
            "by vector.");

    finishTest();
}

void testRectanglesSplit() {
    beginTest();

    Rectangle r1(2, 10);
    Rectangle r2(2, 20);
    Rectangle r3(2, 30);
    Rectangles r({r1, r2, r3});
    r.split_horizontally(1, 1);
    std::pair<Rectangle, Rectangle> r2_hsplit = r2.split_horizontally(1);

    checkEqual<Rectangle>(r1, r[0], "First rectangle unchanged.");
    checkEqual<Rectangle>(r3, r[3], "Fourth rectangle unchanged.");
    checkEqual<int32_t>(r.size(), 4, "Rectangles size increased "
            "with splitting horizontally.");
    checkEqual<Rectangle>(r[1], r2_hsplit.first,
                          "First rectangle from the split is correct.");
    checkEqual<Rectangle>(r[2], r2_hsplit.second,
                          "Second rectangle from the split is correct.");

    r.split_vertically(0, 1);
    std::pair<Rectangle, Rectangle> r1_vsplit = r1.split_vertically(1);
    checkEqual<int32_t>(r.size(), 5, "Rectangles size increased with splitting "
            "vertically.");
    checkEqual<Rectangle>(r[0], r1_vsplit.first, "First rectangle was splitted "
            "correctly. (1/2)");
    checkEqual<Rectangle>(r[1], r1_vsplit.second,
                          "First rectangle was splitted "
                                  "correctly. (2/2)");

    finishTest();
}

int main() {
    testRectanglesConstructors();
    testRectanglesGetRectangle();
    testRectanglesEquality();
    testRectanglesMoveByVector();
    testRectanglesSplit();
}

