#pragma once

class TupleData {
public:
    double x;
    double y;
    double z;
    double w;

    TupleData(double x1, double y1, double z1, double w1) {
        x = x1;
        y = y1;
        z = z1;
        w = w1;
    }
};

class Tuple {
public:
    static bool isPoint(TupleData a) {
        return a.w == 1.0;
    }
};


void testTupleisPoint() {
    TupleData a(4.3, -4.2, 3, 1.0);

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