#ifndef SIMULATION
#define SIMULATION

#include "block.hpp"

namespace OSK {

class Simulation {

public:
    // Methods
    Simulation(double* timeSteps, double maxTime, std::vector<std::vector<Block*>> &stages);
    void run();

    // Variables
    double* timeSteps;
    double maxTime;
    std::vector<std::vector<Block*>> stages;
    int stop; // Might need to be static

};

}

#endif