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

class PointData {
public:
    double x;
    double y;
    double z;
    double w;

    PointData(double x1, double y1, double z1) {
        x = x1;
        y = y1;
        z = z1;
        w = 1;
    }
};

class VectorData {
public:
    double x;
    double y;
    double z;
    double w;

    VectorData(double x1, double y1, double z1) {
        x = x1;
        y = y1;
        z = z1;
        w = 0;
    }
};


class Tuple {
public:
    static bool isPoint(TupleData a) {
        return a.w == 1.0;
    }
};

class Point {
public:
    static bool EqualsTuple(PointData p, TupleData t) {
        if (Operations::Equal(p.x, t.x) && Operations::Equal(p.y, t.y)
            && Operations::Equal(p.z, t.z) && Operations::Equal(p.w, t.w)) {
             return true;
        }
        return false;
    }
};

class Vector {
public:
    static bool EqualsTuple(VectorData v, TupleData t) {
        if (Operations::Equal(v.x, t.x) && Operations::Equal(v.y, t.y)
            && Operations::Equal(v.z, t.z) && Operations::Equal(v.w, t.w)) {
            return true;
        }
        return false;
    }
};

void testTupleisPoint() {
    TupleData a(4.3, -4.2, 3.1, 1.0);
    bool testPassed = false;

    if (Operations::Equal(a.x, 4.3) && Operations::Equal(a.y, -4.2) 
        && Operations::Equal(a.z, 3.1) && Operations::Equal(a.w, 1.0)) {
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

    if (Operations::Equal(a.x, 4.3) && Operations::Equal(a.y, -4.2)
        && Operations::Equal(a.z, 3.1) && Operations::Equal(a.w, 0.0)) {
        testPassed = true;
    }

    if (testPassed) {
        printf("Test Passed: testTupleisVector\n");
    }
    else {
        printf("Test Failed: testTupleisVector\n");
    }
}

void testPointCreatesTupleWith1() {
    // Tests that creating a Point is equivalent to creating a Tuple with w of 1.0
    PointData p(4, -4, 3);
    TupleData t(4, -4, 3, 1);
    bool testPassed = false;

    if (Point::EqualsTuple(p, t)) {
        testPassed = true;
    }

    if (testPassed) {
        printf("Test Passed: testPointCreatesTupleWith1\n");
    }
    else {
        printf("Test Failed: testPointCreatesTupleWith1\n");
    }
}

void testVectorCreatesTupleWith0() {
    // Tests that creating a Point is equivalent to creating a Tuple with w of 1.0
    VectorData v(4, -4, 3);
    TupleData t(4, -4, 3, 0);
    bool testPassed = false;

    if (Vector::EqualsTuple(v, t)) {
        testPassed = true;
    }

    if (testPassed) {
        printf("Test Passed: testVectorCreatesTupleWith0\n");
    }
    else {
        printf("Test Failed: testVectorCreatesTupleWith0\n");
    }
}


void run_tuple_tests() {
    testTupleisPoint();
    testTupleisVector();
    testPointCreatesTupleWith1();
    testVectorCreatesTupleWith0();
}