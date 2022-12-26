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
    TupleData a(4.3, -4.2, 3.1, 1.0);
    bool testPassed = false;

    if (Operations::equal(a.x, 4.3) && Operations::equal(a.y, -4.2) 
        && Operations::equal(a.z, 3.1) && Operations::equal(a.w, 1.0)) {
        testPassed = true;
    }

    if (testPassed) {
        printf("Test Passed: testTupleisPoint\n");
    }
    else {
        printf("Test Failed: testTupleisPoint\n");
    }
}

void testTupleisVector() {
    TupleData a(4.3, -4.2, 3.1, 0.0);
    bool testPassed = false;

    if (Operations::equal(a.x, 4.3) && Operations::equal(a.y, -4.2)
        && Operations::equal(a.z, 3.1) && Operations::equal(a.w, 0.0)) {
        testPassed = true;
    }

    if (testPassed) {
        printf("Test Passed: testTupleisVector\n");
    }
    else {
        printf("Test Failed: testTupleisVector\n");
    }
}


void run_tuple_tests() {
    testTupleisPoint();
    testTupleisVector();
}