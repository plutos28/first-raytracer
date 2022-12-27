#include <iostream>

#include "operations.h"
#include "tuple.h"

void run_tests();

int main()
{
    TupleData t3;
    std::cout << t3.w;
    // Run all the tests
    run_tests();

    return 0;
}

void run_tests() {
    run_tuple_tests();
}