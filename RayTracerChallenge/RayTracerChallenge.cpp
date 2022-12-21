#include <iostream>
#include <assert.h>
#include <cstdio>

#include "tuple.h"

void run_tests();

int main()
{
    Tuple a;
    a.x = 4.3;
    a.y = -4.2;
    a.z = 3.1;
    a.w = 1.0;

    // Run all the tests
    run_tests();

    return 0;
}

void run_tests() {
    run_tuple_tests();
}