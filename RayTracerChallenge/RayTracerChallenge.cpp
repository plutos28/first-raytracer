#include <iostream>

#include "operations.h"
#include "tuple.h"

void run_tests();

int main()
{
    TupleData t1(3, -2, 5, 0); 
    PointData t2; 

    // std::cout << Tuple::Add(t1, t2).w << "\n";

    PointData p1;
    // std::cout << Tuple::Add(p1, t2).w << "\n";

    // std::cout << Tuple::Equal(p1, t2) << "\n";

    // Run all the tests
    run_tests();

    return 0;
}

void run_tests() {
    run_tuple_tests();
}