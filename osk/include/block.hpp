#ifndef BLOCK
#define BLOCK

#include <vector>
#include "state.hpp"

namespace OSK {

class Block {

public:
    // Methods
    Block();
    void addIntegrator(double &state, double &derivative);
    virtual void initialize() {};
    virtual void update() {};
    virtual void report() {};

    // Variables
    State* integrator;
    std::vector<State*> states;
    int initCount = 0;
};

}

#endif