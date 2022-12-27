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

// be able to std::cout TupleData like this: (x, y, z, w)
std::ostream& operator<<(std::ostream &s, const TupleData &t) {
    return s << typeid(t).name() << "(" << t.x << ", " << t.y << ", " << t.z << ", " << t.w << ")";
}
 

class PointData : public TupleData {
public:
    PointData(double x1 = 0, double y1 = 0, double z1 = 0) {
        x = x1;
        y = y1;
        z = z1;
        w = 1;
    }
};

class VectorData : public TupleData {
public:
    VectorData(double x1 = 0, double y1 = 0, double z1 = 0) {
        x = x1;
        y = y1;
        z = z1;
        w = 0;
    }
};


class Tuple {
public:
    static bool IsPoint(TupleData a) {
       return Operations::Equal(a.x, 4.3) && Operations::Equal(a.y, -4.2)
            && Operations::Equal(a.z, 3.1) && Operations::Equal(a.w, 1.0);
    }

    static bool IsVector(TupleData a) {
        return Operations::Equal(a.x, 4.3) && Operations::Equal(a.y, -4.2)
            && Operations::Equal(a.z, 3.1) && Operations::Equal(a.w, 0.0);
    }

    static bool Equal(TupleData t1, TupleData t2) {
        return Operations::Equal(t1.x, t2.x) && Operations::Equal(t1.y, t2.y)
            && Operations::Equal(t1.z, t2.z) && Operations::Equal(t1.w, t2.w);
    }

    static TupleData Add(TupleData t1, TupleData t2) {
        TupleData result(0, 0, 0, 0);

        result.x = t1.x + t2.x;
        result.y = t1.y + t2.y;
        result.z = t1.z + t2.z;
        result.w = t1.w + t2.w;

        return result;
    }

    
};

class Point : public Tuple {
public:
    static VectorData SubtractPoint(PointData p1, PointData t2) {
        // Subtracting two points(p - p = v)
        VectorData resultVector;
        resultVector.x = p1.x - t2.x;
        resultVector.y = p1.y - t2.y;
        resultVector.z = p1.z - t2.z;
        return resultVector;
    }

    static PointData SubtractVector(PointData p1, VectorData v1) {
        // Subtracting vector from point(p - v = p)
        PointData resultPoint;
        resultPoint.x = p1.x - v1.x;
        resultPoint.y = p1.y - v1.y;
        resultPoint.z = p1.z - v1.z;
        return resultPoint;
    }

};

class Vector : public Tuple {
public:
    static VectorData SubtractVector(VectorData v1, VectorData v2) {
        // Subtracting two vectors(v - v = v)
        VectorData resultVector;
        resultVector.x = v1.x - v2.x;
        resultVector.y = v1.y - v2.y;
        resultVector.z = v1.z - v2.z;
        return resultVector;
    }
};

void testTupleisPoint() {
    TupleData a(4.3, -4.2, 3.1, 1.0);
    bool testPassed = false;

    if (Tuple::IsPoint(a)) {
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

    if (Tuple::IsVector(a)) {
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

    if (Point::Equal(p, t)) {
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

    if (Vector::Equal(v, t)) {
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
    // Test that you can add two tuples 
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
        std::cout << "\tResult: " << resultTuple << "\n";
        std::cout << "\tExpected: " << expectedTuple << "\n";
    }
    else {
        std::cout << "Test Failed: testAddTuples\n";
        std::cout << "\tResult: " << resultTuple << "\n";
        std::cout << "\tExpected: " << expectedTuple << "\n";
    }
}

void testSubtractTwoPoints() {
    // Test that you can subtract two points(p - p = v)
    PointData p1(3, 2, 1); // a point
    PointData p2(5, 6, 7); // a point
    VectorData expectedVector(-2, -4, -6);
    bool testPassed = false;

    VectorData resultVector = Point::SubtractPoint(p1, p2); 

    if(Vector::Equal(resultVector, expectedVector)) {
        testPassed = true;
    }

    if (testPassed) {
        std::cout << "Test Passed: testSubtractTwoPoints\n";
        std::cout << "\tResult: " << resultVector << "\n";
        std::cout << "\tExpected: " << expectedVector << "\n";
    }
    else {
        std::cout << "Test Failed: testSubtractTwoPoints\n";
        std::cout << "\tResult: " << resultVector << "\n";
        std::cout << "\tExpected: " << expectedVector << "\n";
    }
}

void testSubtractVectorFromPoint() {
    // Test that you can subtract a vector from a point(p - v = p) 
    PointData p1(3, 2, 1); 
    VectorData v1(5, 6, 7); 
    PointData expectedPoint(-2, -4, -6);
    bool testPassed = false;

    PointData resultPoint = Point::SubtractVector(p1, v1); 

    if(Point::Equal(resultPoint, expectedPoint)) {
        testPassed = true;
    }

    if (testPassed) {
        std::cout << "Test Passed: testSubtractVectorFromPoint\n";
        std::cout << "\tResult: " << resultPoint << "\n";
        std::cout << "\tExpected: " << expectedPoint << "\n";
    }
    else {
        std::cout << "Test Failed: testSubtractVectorFromPoint\n";
        std::cout << "\tResult: " << resultPoint << "\n";
        std::cout << "\tExpected: " << expectedPoint << "\n";
    }
}

void testSubtractTwoVectors() {
    // Test that you can subtract two vectors(v - v = v) 
    VectorData v1(3, 2, 1); 
    VectorData v2(5, 6, 7); 
    VectorData expectedVector(-2, -4, -6);
    bool testPassed = false;

    VectorData resultVector = Vector::SubtractVector(v1, v2); 

    if(Vector::Equal(resultVector, expectedVector)) {
        testPassed = true;
    }

    if (testPassed) {
        std::cout << "Test Passed: testSubtractTwoVectors\n";
        std::cout << "\tResult: " << resultVector << "\n";
        std::cout << "\tExpected: " << expectedVector << "\n";
    }
    else {
        std::cout << "Test Failed: testSubtractTwoVectors\n";
        std::cout << "\tResult: " << resultVector << "\n";
        std::cout << "\tExpected: " << expectedVector << "\n";
    }
}



void run_tuple_tests() {
    testTupleisPoint();
    testTupleisVector();
    testPointCreatesTupleWith1();
    testVectorCreatesTupleWith0();
    testTuplesEqual();
    testAddTuples();
    testSubtractTwoPoints();
    testSubtractVectorFromPoint();
    testSubtractTwoVectors();
}