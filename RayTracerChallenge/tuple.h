#pragma once

class Tuple {
public:
    double x;
    double y;
    double z;
    double w;

    Tuple(double x1 = 0, double y1 = 0, double z1 = 0, double w1 = 0) {
        x = x1;
        y = y1;
        z = z1;
        w = w1;
    }

    bool isPoint() {
        return Operations::equal(w, 1.0);
    }

    bool isVector() {
        return Operations::equal(w, 0.0);
    }

    bool equal(Tuple t2) {
        return Operations::equal(x, t2.x) && Operations::equal(y, t2.y)
            && Operations::equal(z, t2.z) && Operations::equal(w, t2.w);
    }

    Tuple add(Tuple t2) {
        // Currently doesn't modify the tuple, just returns a new tuple
        Tuple result(x, y, z, w);

        result.x += t2.x;
        result.y += t2.y;
        result.z += t2.z;
        result.w += t2.w;

        return result;
    }

    Vector subtract(Point p2) {
       Vector result(x, y, z);
       return result;
    }
    
};

// be able to std::cout TupleData like this: (x, y, z, w)
std::ostream& operator<<(std::ostream& s, const Tuple& t) {
    return s << typeid(t).name() << "(" << t.x << ", " << t.y << ", " << t.z << ", " << t.w << ")";
}

class Point : public Tuple {
public:
    Point(double x1 = 0, double y1 = 0, double z1 = 0) {
        x = x1;
        y = y1;
        z = z1;
        w = 1.0;
    }

    // Vector subtract(Point p2) {
    //     Vector result(x, y, z);

    //     result.x -= p2.x;
    //     result.y -= p2.y;
    //     result.z -= p2.z;
    //     result.w -= p2.w;

    //     return result;
    // }
};

class Vector : public Tuple {
public:
    Vector(double x1 = 0, double y1 = 0, double z1 = 0) {
        x = x1;
        y = y1;
        z = z1;
        w = 0.0;
    }
};

void testTupleisPoint() {
    Tuple a(4.3, -4.2, 3.1, 1.0);
    bool testPassed = false;

    if (a.isPoint()) {
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
    Tuple a(4.3, -4.2, 3.1, 0.0);
    bool testPassed = false;

    if (a.isVector()) {
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
    Point p(4, -4, 3);
    Tuple t(4, -4, 3, 1);
    bool testPassed = false;

    if (p.equal(t)) {
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
    Vector v(4, -4, 3);
    Tuple t(4, -4, 3, 0);
    bool testPassed = false;

    if (v.equal(t)) {
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
    Tuple t1(4, -4, 3, 1);
    Tuple t2(4, -4, 3, 1);
    bool testPassed = false;

    if (t1.equal(t2)) {
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
    Tuple t1(3, -2, 5, 1); // a point
    Tuple t2(-2, 3, 1, 0); // a vector
    Tuple expectedTuple(1, 1, 6, 1);
    bool testPassed = false;

    Tuple resultTuple = t1.add(t2); // return a new tuple

    if(resultTuple.equal(expectedTuple)) {
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
    Point p1(3, 2, 1); 
    Point p2(5, 6, 7); 
    Vector expectedVector(-2, -4, -6);
    bool testPassed = false;

    Vector resultVector = p1.subtract(p2); 

    if(resultVector.equal(expectedVector)) {
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

// void testSubtractVectorFromPoint() {
//     // Test that you can subtract a vector from a point(p - v = p) 
//     PointData p1(3, 2, 1); 
//     VectorData v1(5, 6, 7); 
//     PointData expectedPoint(-2, -4, -6);
//     bool testPassed = false;

//     PointData resultPoint = Point::subtractVector(p1, v1); 

//     if(Point::equal(resultPoint, expectedPoint)) {
//         testPassed = true;
//     }

//     if (testPassed) {
//         std::cout << "Test Passed: testSubtractVectorFromPoint\n";
//         std::cout << "\tResult: " << resultPoint << "\n";
//         std::cout << "\tExpected: " << expectedPoint << "\n";
//     }
//     else {
//         std::cout << "Test Failed: testSubtractVectorFromPoint\n";
//         std::cout << "\tResult: " << resultPoint << "\n";
//         std::cout << "\tExpected: " << expectedPoint << "\n";
//     }
// }

// void testSubtractTwoVectors() {
//     // Test that you can subtract two vectors(v - v = v) 
//     VectorData v1(3, 2, 1); 
//     VectorData v2(5, 6, 7); 
//     VectorData expectedVector(-2, -4, -6);
//     bool testPassed = false;

//     VectorData resultVector = Vector::subtractVector(v1, v2); 

//     if(Vector::equal(resultVector, expectedVector)) {
//         testPassed = true;
//     }

//     if (testPassed) {
//         std::cout << "Test Passed: testSubtractTwoVectors\n";
//         std::cout << "\tResult: " << resultVector << "\n";
//         std::cout << "\tExpected: " << expectedVector << "\n";
//     }
//     else {
//         std::cout << "Test Failed: testSubtractTwoVectors\n";
//         std::cout << "\tResult: " << resultVector << "\n";
//         std::cout << "\tExpected: " << expectedVector << "\n";
//     }
// }

// void testNegateVector() {
//     // Test that you can negate vector 
//     VectorData v(1, -2, 3); 
//     VectorData expectedVector(-1, 2, -3);
//     bool testPassed = false;

//     VectorData resultVector = Vector::negate(v);

//     if(Vector::equal(resultVector, expectedVector)) {
//         testPassed = true;
//     }

//     if (testPassed) {
//         std::cout << "Test Passed: testNegateVector\n";
//         std::cout << "\tResult: " << resultVector << "\n";
//         std::cout << "\tExpected: " << expectedVector << "\n";
//     }
//     else {
//         std::cout << "Test Failed: testNegateVector\n";
//         std::cout << "\tResult: " << resultVector << "\n";
//         std::cout << "\tExpected: " << expectedVector << "\n";
//     }
// }

// void testNegateTuple() {
//     // Test that you can negate tuple
//     TupleData t(1, -2, 3); 
//     TupleData expectedTuple(-1, 2, -3);
//     bool testPassed = false;

//     TupleData resultTuple = Tuple::negate(t); 

//     if(Tuple::equal(resultTuple, expectedTuple)) {
//         testPassed = true;
//     }

//     if (testPassed) {
//         std::cout << "Test Passed: testNegateTuple\n";
//         std::cout << "\tResult: " << resultTuple << "\n";
//         std::cout << "\tExpected: " << expectedTuple << "\n";
//     }
//     else {
//         std::cout << "Test Failed: testNegateTuple\n";
//         std::cout << "\tResult: " << resultTuple << "\n";
//         std::cout << "\tExpected: " << expectedTuple << "\n";
//     }
// }

// void testMultiplyTupleByScalar() {
//     TupleData t(1, -2, 3, -4);
//     TupleData expectedTuple(3.5, -7, 10.5, -14);
//     double scalar = 3.5;
//     bool testPassed = false;

//     TupleData resultTuple = Tuple::multiply(t, scalar); 

//     if(Tuple::equal(resultTuple, expectedTuple)) {
//         testPassed = true;
//     }

//     if (testPassed) {
//         std::cout << "Test Passed: testMultiplyTupleByScalar\n";
//         std::cout << "\tResult: " << resultTuple << "\n";
//         std::cout << "\tExpected: " << expectedTuple << "\n";
//     }
//     else {
//         std::cout << "Test Failed: testMultiplyTupleByScalar\n";
//         std::cout << "\tResult: " << resultTuple << "\n";
//         std::cout << "\tExpected: " << expectedTuple << "\n";
//     }
// }

// void testMulitplyTupleByFraction() {
//     TupleData t(1, -2, 3, -4);
//     TupleData expectedTuple(0.5, -1, 1.5, -2);
//     double scalar = 0.5;
//     bool testPassed = false;

//     TupleData resultTuple = Tuple::multiply(t, scalar); 

//     if(Tuple::equal(resultTuple, expectedTuple)) {
//         testPassed = true;
//     }

//     if (testPassed) {
//         std::cout << "Test Passed: testMulitplyTupleByFraction\n";
//         std::cout << "\tResult: " << resultTuple << "\n";
//         std::cout << "\tExpected: " << expectedTuple << "\n";
//     }
//     else {
//         std::cout << "Test Failed: testMulitplyTupleByFraction\n";
//         std::cout << "\tResult: " << resultTuple << "\n";
//         std::cout << "\tExpected: " << expectedTuple << "\n";
//     }
// }

// void testDivideTupleByScalar() {
//     TupleData t(1, -2, 3, -4);
//     TupleData expectedTuple(0.5, -1, 1.5, -2);
//     double scalar = 2;
//     bool testPassed = false;

//     TupleData resultTuple = Tuple::divide(t, scalar); 

//     if(Tuple::equal(resultTuple, expectedTuple)) {
//         testPassed = true;
//     }

//     if (testPassed) {
//         std::cout << "Test Passed: testDivideTupleByScalar\n";
//         std::cout << "\tResult: " << resultTuple << "\n";
//         std::cout << "\tExpected: " << expectedTuple << "\n";
//     }
//     else {
//         std::cout << "Test Failed: testDivideTupleByScalar\n";
//         std::cout << "\tResult: " << resultTuple << "\n";
//         std::cout << "\tExpected: " << expectedTuple << "\n";
//     }
// }

// void testMagnitudesOfVectors() {
//     bool testPassed = false;
//     VectorData testVectors[] = {
//         VectorData(1, 0, 0),
//         VectorData(0, 1, 0),
//         VectorData(0, 0, 1),
//         VectorData(1, 2, 3),
//         VectorData(-1, -2, -3)
//     };
//     double expectedMagnitudes[] = {1, 1, 1, sqrt(14), sqrt(14)};

//     for(int i=0; i < sizeof(testVectors) / sizeof(VectorData); i++) {
//         if(Operations::equal(Vector::magnitude(testVectors[i]),expectedMagnitudes[i])) {
//             testPassed = true;
//         } else {
//             testPassed = false;
//         }

//         if (testPassed) {
//             std::cout << "Test Passed: testMagnitudesOfVectors" << "(" << i << ")" << "\n";
//             std::cout << "\tResult: " << Vector::magnitude(testVectors[i]) << "\n";
//             std::cout << "\tExpected: " << expectedMagnitudes[i] << "\n";
//         }
//         else {
//             std::cout << "Test Failed: testMagnitudesOfVectors" << "(" << i << ")" << "\n";
//             std::cout << "\tResult: " << Vector::magnitude(testVectors[i]) << "\n";
//             std::cout << "\tExpected: " << expectedMagnitudes[i] << "\n";
//         }
//     }
// }

// void testNormalizeVector() {
//     bool testPassed = false;
//     VectorData testVectors[] = {
//         VectorData(4, 0, 0),
//         VectorData(1, 2, 3),
//     };
//     VectorData expectedVectors[] = {
//         VectorData(1, 0, 0),
//         VectorData(0.26726, 0.53452, 0.80178),
//     };

//     for(int i=0; i < sizeof(testVectors) / sizeof(VectorData); i++) {
//         if(Vector::equal(Vector::normalize(testVectors[i]), expectedVectors[i])) {
//             testPassed = true;
//         } else {
//             testPassed = false;
//         }

//         if (testPassed) {
//             std::cout << "Test Passed: testNormalizeVector" << "(" << i << ")" << "\n";
//             std::cout << "\tResult: " << Vector::normalize(testVectors[i]) << "\n";
//             std::cout << "\tExpected: " << expectedVectors[i] << "\n";
//         }
//         else {
//             std::cout << "Test Failed: testNormalizeVector" << "(" << i << ")" << "\n";
//             std::cout << "\tResult: " << Vector::normalize(testVectors[i]) << "\n";
//             std::cout << "\tExpected: " << expectedVectors[i] << "\n";
//         }
//     }
// }

// void testMagnitudeOfNormalizedVector() {
//     VectorData v(1, 2, 3);
//     double expectedMagnitude = 1;
//     bool testPassed = false;

//     double resultMagnitude = Vector::magnitude(Vector::normalize(v)); 

//     if(Tuple::equal(resultMagnitude, expectedMagnitude)) {
//         testPassed = true;
//     }

//     if (testPassed) {
//         std::cout << "Test Passed: testMagnitudeOfNormalizedVector\n";
//         std::cout << "\tResult: " << resultMagnitude << "\n";
//         std::cout << "\tExpected: " << expectedMagnitude << "\n";
//     }
//     else {
//         std::cout << "Test Failed: testMagnitudeOfNormalizedVector\n";
//         std::cout << "\tResult: " << resultMagnitude << "\n";
//         std::cout << "\tExpected: " << expectedMagnitude << "\n";
//     }
// }

void run_tuple_tests() {
    testTupleisPoint();
    testTupleisVector();
    testPointCreatesTupleWith1();
    testVectorCreatesTupleWith0();
    testTuplesEqual();
    testAddTuples();
    testSubtractTwoPoints();
    // testSubtractVectorFromPoint();
    // testSubtractTwoVectors();
    // testNegateVector();
    // testNegateTuple();
    // testMultiplyTupleByScalar();
    // testMulitplyTupleByFraction();
    // testDivideTupleByScalar();
    // testMagnitudesOfVectors();
    // testNormalizeVector();
    // testMagnitudeOfNormalizedVector();
}