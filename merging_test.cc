#include "testing.h"
#include "geometry.h"

#define rect_pair std::pair<Rectangle, Rectangle>

void mergeHorizontallyTest() {
    beginTest();

    Rectangle r1(1, 1, Position(1, 1));
    Rectangle r2(1, 2, Position(1, 2));
    Rectangle r = merge_horizontally(r1, r2);
    checkEqual<Rectangle>(r, Rectangle(1, 3, Position(1, 1)),
                          "Rectangle merged horizontally properly.");

    Rectangles rects1({r1, r2});
    rect_pair rectsPair = r.split_horizontally(1);
    Rectangles rects2({rectsPair.first, rectsPair.second});
    checkEqual<Rectangles>(rects1, rects2,
                           "Rectangle merge_horizontally "
                                   "and split_horizontally are commutative.");

    finishTest();
}

void mergeVerticallyTest() {
    beginTest();

    Rectangle r1(1, 2, Position(1, 1));
    Rectangle r2(2, 2, Position(2, 1));
    Rectangle r = merge_vertically(r1, r2);
    checkEqual<Rectangle>(r, Rectangle(3, 2, Position(1, 1)),
                          "Rectangle merged vertically properly.");

    Rectangles rects1({r1, r2});
    rect_pair rectsPair = r.split_vertically(1);
    Rectangles rects2({rectsPair.first, rectsPair.second});
    checkEqual<Rectangles>(rects1, rects2,
                           "Rectangle merge_vertically "
                                   "and split_vertically are commutative.");

    finishTest();
}

int main() {
    mergeHorizontallyTest();
    mergeVerticallyTest();
}
