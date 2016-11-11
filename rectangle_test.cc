#include "testing.h"
#include "geometry.h"

void testRectangleConstructors() {
    beginTest();

    Rectangle r(2, 5, Position(-1, 3));
    checkEqual<long long>(r.width(), 2, "Set width correctly.");
    checkEqual<long long>(r.height(), 5, "Set height correctly.");
    checkEqual<Position>(r.pos(), Position(-1, 3), "Set position correctly.");

    finishTest();
}

int main() {
    testRectangleConstructors();
}
