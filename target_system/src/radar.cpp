#include<iostream>
#include "../include/radar.hpp"

const double R = 180 / 3.14159;

Radar::Radar(Target* target, double theta, double wn, double zeta) {
    x1 = theta / R;
    x2 = 0.0;
    this->wn = wn;
    this->zeta = zeta;
    this->target = target;

    addIntegrator(x1, x1d);
    addIntegrator(x2, x2d);
}

void Radar::update() {
    double theta_target = atan(target->y / target->x);
    theta_err = theta_target - x1;
    if(fabs(theta_err * R) < 1.0 && Simulation::stop == 0) {
        Simulation::stop = 1;
    }

    x1d = x2;
    x2d = theta_err * wn * wn - 2.0 * zeta * wn * x2;
}

void Radar::report() {
    if(State::sample(1.0) || State::tickFirst || State::tickLast) {
        printf("%12s %8.3f %8.3f\n", "Radar", State::time, theta_err * R);
        printf("\n");
    }
}