#include <iostream>
#include <typeinfo>
#include <cmath>

#include "operations.h"
#include "tuple.h"

void run_tests();

class Projectile {
public:
    Point position;
    Vector velocity;

    Projectile(Point p, Vector v) {
        position = p;
        velocity = v;
    }
};

struct Environment {
    Vector gravity;
    Vector wind;
};

Projectile tick(Environment environment, Projectile projectile);

int main()
{
    // firing virtual projectiles
    std::cout << "***** Firing Projectiles *****\n";

    // Run all the tests
    //run_tests();

    return 0;
}

void run_tests() {
    run_tuple_tests();
}

Projectile tick(Environment environment, Projectile projectile) {
    Point position;
    Vector velocity;

    position = projectile.position.add(projectile.velocity);
    velocity = projectile.velocity.add(environment.gravity).add(environment.wind);

    return Projectile(position, velocity);
}