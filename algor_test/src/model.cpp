#include <iostream>
#include "../include/model.hpp"

Model::Model(double x10_, double x20_) {
    x10 = x10_;
    x20 = x20_;

    addIntegrator(x1, x1d);
    addIntegrator(x2, x2d);
}

void Model::initialize() {
    std::cout << "Starting Model...\n";

    if(initCount == 0) {
        x1 = x10;
        x2 = x20;
    }
}

void Model::update() {
    x1d = x2;
    x2d = -State::time * x1;
}

void Model::report() {
    if(State::sample(0.8) || State::tickLast) {
        printf("%8.3f %8.6f\n", State::time, this->x1);
    }
}