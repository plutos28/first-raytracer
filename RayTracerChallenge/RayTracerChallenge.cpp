#include <iostream>

#include "operations.h"
#include "tuple.h"

void run_tests();

int main()
{
    TupleData t1(3, -2, 5, 0); 
    TupleData t2(-2, 3, 1, 0); 

    std::cout << Tuple::Add(t1, t2).w << "\n";

    // Run all the tests
    run_tests();

    return 0;
}

void run_tests() {
    run_tuple_tests();
}