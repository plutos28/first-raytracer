#include <iostream>

#include "operations.h"
#include "tuple.h"

void run_tests();

int main()
{
    PointData v1(1, 1, 1);
    PointData v2(1, 1, 1);
    std::cout << Point::Equal(v1, v2) << "\n";
    // Run all the tests
    run_tests();

    return 0;
}

void run_tests() {
    run_tuple_tests();
}