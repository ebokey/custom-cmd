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
    static int stop; // If less than zero, the kernel is instructed to terminate the simulation after the current time-step
    // I don't like the variable name 'stop' because it is also used to tell the simulation to move onto the next stage when
    //  stop = 1 -- I think something like 'status' would be more appropriate
};

}

#endif