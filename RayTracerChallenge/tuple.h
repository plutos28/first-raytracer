#pragma once
#include <assert.h>

struct Tuple {
    double x;
    double y;
    double z;
    double w;
};

bool tuple_is_point(Tuple a) {
    return a.w == 1.0;
}

void test_tuple_is_point() {
    Tuple a;
    a.x = 4.3;
    a.y = -4.2;
    a.z = 3.1;
    a.w = 1.0;

    assert(tuple_is_point(a));
}

void run_tuple_tests() {
    test_tuple_is_point();
}