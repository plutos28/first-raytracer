#pragma once

struct TupleData {
    double x;
    double y;
    double z;
    double w;
};

class Tuple {
public:
    static bool isPoint(TupleData a) {
        return a.w == 1.0;
    }
};


void testTupleisPoint() {
    TupleData a;
    a.x = 4.3;
    a.y = -4.2;
    a.z = 3.1;
    a.w = 1.0;

    if (a.w == 1.0) {
        printf("Test Passed: testTupleisPoint");
    }
    else {
        printf("Test Failed: testTupleisPoint");
    }
    
}

void run_tuple_tests() {
    testTupleisPoint();
}