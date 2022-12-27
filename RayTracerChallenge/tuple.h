#pragma once

class TupleData {
public:
    double x;
    double y;
    double z;
    double w;

    TupleData(double x1 = 0, double y1 = 0, double z1 = 0, double w1 = 0) {
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
    const double w = 1;

    PointData(double x1 = 0, double y1 = 0, double z1 = 0) {
        x = x1;
        y = y1;
        z = z1;
    }
};

class VectorData {
public:
    double x;
    double y;
    double z;
    const double w = 0;

    VectorData(double x1 = 0, double y1 = 0, double z1 = 0) {
        x = x1;
        y = y1;
        z = z1;
    }
};


class Tuple {
public:
    static bool isPoint(TupleData a) {
        return a.w == 1.0;
    }

    static bool Equal(TupleData t1, TupleData t2) {
        if (Operations::Equal(t1.x, t2.x) && Operations::Equal(t1.y, t2.y)
            && Operations::Equal(t1.z, t2.z) && Operations::Equal(t1.w, t2.w)) {
            return true;
        }
        return false;
    }

    static TupleData Add(TupleData t1, TupleData t2) {
        TupleData result(0, 0, 0, 0);

        return result;
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

    static bool Equal(PointData p1, PointData p2) {
        if (Operations::Equal(p1.x, p2.x) && Operations::Equal(p1.y, p2.y)
            && Operations::Equal(p1.z, p2.z)) {
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

    
    static bool Equal(VectorData v1, VectorData v2) {
        if (Operations::Equal(v1.x, v2.x) && Operations::Equal(v1.y, v2.y)
            && Operations::Equal(v1.z, v2.z)) {
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
        std::cout << "Test Passed: testTupleisPoint\n";
    }
    else {
        std::cout << "Test Failed: testTupleisPoint\n";
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
        std::cout << "Test Passed: testTupleisVector\n";
    }
    else {
        std::cout << "Test Failed: testTupleisVector\n";
    }
}

void testPointCreatesTupleWith1() {
    // Test that creating a Point is equivalent to creating a Tuple with w of 1.0
    PointData p(4, -4, 3);
    TupleData t(4, -4, 3, 1);
    bool testPassed = false;

    if (Point::EqualsTuple(p, t)) {
        testPassed = true;
    }

    if (testPassed) {
        std::cout << "Test Passed: testPointCreatesTupleWith1\n";
    }
    else {
        std::cout << "Test Failed: testPointCreatesTupleWith1\n";
    }
}

void testVectorCreatesTupleWith0() {
    // Test that creating a Vector is equivalent to creating a Tuple with w of 0.0
    VectorData v(4, -4, 3);
    TupleData t(4, -4, 3, 0);
    bool testPassed = false;

    if (Vector::EqualsTuple(v, t)) {
        testPassed = true;
    }

    if (testPassed) {
        std::cout << "Test Passed: testVectorCreatesTupleWith0\n";
    }
    else {
        std::cout << "Test Failed: testVectorCreatesTupleWith0\n";
    }
}

void testTuplesEqual() {
    // Test that you can check the equivalence of two tuples
    TupleData t1(4, -4, 3, 1);
    TupleData t2(4, -4, 3, 1);
    bool testPassed = false;

    if (Tuple::Equal(t1, t2)) {
        testPassed = true;
    }

    if (testPassed) {
        std::cout << "Test Passed: testTuplesEqual\n";
    }
    else {
        std::cout << "Test Failed: testTuplesEqual\n";
    }
}

void testAddTuples() {
    // Test that you acn add two tuples 
    TupleData t1(3, -2, 5, 1); // a point
    TupleData t2(-2, 3, 1, 0); // a vector
    TupleData expectedTuple(1, 1, 6, 1);
    bool testPassed = false;

    TupleData resultTuple = Tuple::Add(t1, t2); // return a new tuple

    if(Tuple::Equal(resultTuple, expectedTuple)) {
        testPassed = true;
    }


    if (testPassed) {
        std::cout << "Test Passed: testAddTuples\n";
    }
    else {
        std::cout << "Test Failed: testAddTuples\n";
    }
}



void run_tuple_tests() {
    testTupleisPoint();
    testTupleisVector();
    testPointCreatesTupleWith1();
    testVectorCreatesTupleWith0();
    testTuplesEqual();
    testAddTuples();
}