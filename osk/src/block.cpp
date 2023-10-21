#include "../include/block.hpp"

namespace OSK {

Block::Block() {
    integrator = new State();
}

void Block::addIntegrator(double &state, double &derivative) {
    // Create a pointer to a new instance of the State class
    State* newState = integrator->duplicateState(state, derivative);

    // Add this pointer to the states vector
    states.push_back(newState);
}

}