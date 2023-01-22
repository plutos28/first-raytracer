#include <iostream>
#include <typeinfo>
#include <cmath>

#include "operations.h"
#include "tuple.h"
#include "color.h"
#include "canvas.h"

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

class Environment {
public:
    Vector gravity;
    Vector wind;

    Environment(Vector g, Vector w) {
        gravity = g;
        wind = w;
    }
};

Projectile tick(Environment environment, Projectile projectile);

int main()
{
    // firing virtual projectiles
    std::cout << "***** Firing Projectiles *****\n";
    Projectile p(Point(0, 1, 0), Vector(1, 1, 0).normalize());
    Environment e(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));

    while (p.position.y > 0) {
        p = tick(e, p);
        std::cout << "(x: " << p.position.x << ", y: " << p.position.y << ")\n";
    }

    // Run all the tests
    run_tests();

    Canvas c(5, 5);
    c.writePixel(0, 0, Color(1, 1, 1));
    c.writePixel(1, 2, Color(1, 1, 1));
    c.writePixel(2, 0, Color(1, 1, 1));
    c.writePixel(3, 1, Color(1, 1, 1));

    for (int i = 0; i < c.height; i++) { // row(i)
        for (int j = 0; j < c.width; j++) { // column(j)
            std::cout << *(c.pixels + j + (c.height * i)) << ", ";
        }
        std::cout << "\n";
    }

    return 0;
}

void run_tests() {
    run_tuple_tests();
    run_color_tests();
    run_canvas_tests();
}

Projectile tick(Environment environment, Projectile projectile) {
    Point position;
    Vector velocity;

    position = projectile.position.add(projectile.velocity);
    velocity = projectile.velocity.
        add(environment.gravity).
        add(environment.wind);

    return Projectile(position, velocity);
}