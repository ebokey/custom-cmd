#include<iostream>
#include "../include/missile.hpp"

Missile::Missile(Target* target, double x, double y, double vel) {
    this->x = x;
    this->y = y;
    this->vel = vel;
    this->target = target;

    addIntegrator(this->x, vx);
    addIntegrator(this->y, vy);
}

void Missile::update() {
    double dx = target->x - x;
    double dy = target->y - y;
    d = sqrt(dx*dx + dy*dy);
    vx = vel * dx / d;
    vy = vel * dy / d;
    if(d <= 0.1) {
        Simulation::stop = -1;
    }
}

void Missile::report() {
    if(State::sample(1.0) || State::tickFirst || State::tickLast) {
        printf("%12s %8.3f %8.3f %8.3f %8.3f\n", "Missile", State::time, x, y, d);
    }
}