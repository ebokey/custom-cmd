#include<iostream>
#include "../include/target.hpp"

Target::Target(double x, double y, double vx, double vy) {
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;

    addIntegrator(this->x, this->vx);
    addIntegrator(this->y, this->vy);
}

void Target::report() {

    if(State::sample() || State::tickFirst || State::tickLast) {
        printf("%12s %8.3f %8.3f %8.3f\n", "Target", State::time, x, y);
    }
}