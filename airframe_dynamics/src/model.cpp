#include<iostream>
#include "../include/model.hpp"

Model::Model(double gammma_) {
    gamma0 = gammma_;

    addIntegrator(gamma, gammad);
}

void Model::initialize() {
    std::cout << "Starting Model...\n";

    if(initCount == 0) {
        gamma = gamma0;
        k = 1000.0;
    }

    // Need to increment initCount by 1; do that here, or somewhere else?
}

void Model::update() {
    gamma_cmd = 1.0;
    v = 1000.0;
    a_cmd = k * (gamma_cmd - gamma);
    gammad = a_cmd / v;
}

void Model::report() {
    if(State::sample(0.1)) {
        printf("%8.3f %8.6f\n", State::time, this->gamma);
    }
}