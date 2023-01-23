#include <iostream>
#include <typeinfo>
#include <cmath>
#include <string>

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
    Projectile proj(Point(0, 1, 0), Vector(1, 1, 0).normalize());
    Environment e(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));

    while (proj.position.y > 0) {
        proj = tick(e, proj);
        std::cout << "(x: " << proj.position.x << ", y: " << proj.position.y << ")\n";
    }

    // Run all the tests
    run_tests();

    Canvas c(5, 3);
    Color c1(1.5, 0, 0);
    Color c2(0, 0.5, 0);
    Color c3(-0.5, 0, 1);

    c.writePixel(0, 0, c1);
    c.writePixel(2, 1, c2);
    c.writePixel(4, 2, c3);
    PPM p = CanvasToPPM(c);

    //std::cout << "\n\n" << p.content << "\n";

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