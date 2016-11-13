#include "geometry.h"
#include "testing.h"
#include <iostream>

void testVectorConstructors() {
    beginTest();

    Vector v(3, 4);
    checkEqual<long>(v.x(), 3, "x-coordinate set correctly");
    checkEqual<long>(v.y(), 4, "y-coordinate set correctly");

    Vector w(v);
    checkEqual<long>(w.x(), 3, "x-coordinate set correctly");
    checkEqual<long>(w.y(), 4, "y-coordinate set correctly");

    Vector u(Vector(3, 4));
    checkEqual<long>(u.x(), 3, "x-coordinate set correctly");
    checkEqual<long>(u.y(), 4, "y-coordinate set correctly");

    finishTest();
}

void testVectorEquality() {
    beginTest();

    Vector v(42, 0);
    Vector v2(v);
    Vector w(42, 0);
    checkEqual<Vector>(v, v, "A Vector is equal to itself.");
    checkEqual<Vector>(v, v2,
            "Copy constructor creates equivalent Vector.");
    checkEqual<Vector>(v, w,
            "Vectors initialized with same values are equal.");
    checkEqual<Vector>(v, Vector(42, 0), "Works with rvalues.");

    Vector u(43, 0);
    checkNotEqual<Vector>(v, u,
            "Vectors with different coordinates are not equivalent.");

    finishTest();
}

void testVectorReflection() {
    beginTest();

    Vector v(23, -5);
    Vector u = v.reflection();
    checkEqual<long>(u.x(), -5, "x-coordinate set correctly.");
    checkEqual<long>(u.y(), 23, "x-coordinate set correctly.");

    Vector w(42, 42);
    checkEqual<Vector>(w, w.reflection(),
            "Vectors on x = y are fixed points.");

    finishTest();
}

int main() {
    testVectorConstructors();
    testVectorEquality();
    testVectorReflection();

    return 0;
}
