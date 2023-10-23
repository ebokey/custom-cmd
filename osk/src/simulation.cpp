#include "../include/simulation.hpp"

namespace OSK {

// Declare functions
void runIteration(std::vector<Block*> &currentStage);

// Initialize the static variables in the State class
// Not sure if there is a better spot for these...
double State::time = 0;
double State::defaultTimeStep = 0;
double State::timeStep = 0;
double State::nextTime = 0;
bool State::tickFirst = 0;
bool State::tickLast = 0;
bool State::ready = 0;
int State::kpass = 0;
int Simulation::stop = 0;

Simulation::Simulation(double* timeSteps, double maxTime, std::vector<std::vector<Block*>> &stages) {
    // Constructor goes here
    this->timeSteps = timeSteps;
    this->maxTime = maxTime;
    this->stages = stages;
}

void Simulation::run() {
    // Need to fully flesh out how to handle multiple sim stages
    std::vector<Block*> currentStage;

    // Execute each stage
    for(int i=0; i < stages.size(); i++) {

        // Extract the current model stage and timeStep
        currentStage = stages[i];
        double timeStep = timeSteps[i];

        // Set the static variables
        // State::time should not need to change
        State::defaultTimeStep = timeStep;
        State::timeStep = timeStep;
        State::nextTime = State::time + timeStep;
        State::tickFirst = 1;
        State::ready = 1;

        // Initialize each model
        int j;
        for(j=0; j < currentStage.size(); j++) {
            currentStage[j]->initialize();

            // Report the model
            currentStage[j]->report();
        }

        State::tickFirst = 0;

        // Put a loop here - need to add the rest of the conditions
        while(State::nextTime <= maxTime && Simulation::stop == i) {

            if(State::nextTime == maxTime) {
                State::tickLast = 1;
            }
            
            runIteration(currentStage);
        }

        // Handle potential simulation termination
        if(Simulation::stop < 0) { break; } // Simulation needs to terminate
    }

    // Execute final tick if not already done so and simulation wasn't terminated prematurely
    if(State::time < maxTime && Simulation::stop >= 0) {
        State::nextTime = maxTime;
        State::timeStep = maxTime - State::time;
        State::tickLast = 1;

        runIteration(currentStage);

        // Right now it appears that the simulation oversteps tMax by half a time-step; my guess is that my code doesn't cut off before a half-step
    }
}

/*
runIteration function - runs one iteration of the models which includes updating them, propogating the states, updating the clock, and reporting
*/
void runIteration(std::vector<Block*> &currentStage) {
    int i;

    for(i=0; i < currentStage.size(); i++) {
        currentStage[i]->update();

        // Propogate the states
        for(int j=0; j < currentStage[i]->states.size(); j++) {
            currentStage[i]->states[j]->propogate();
        }
    }

    // Update clock
    State::updateClock();

    // Check if simulation is being terminated
    if(Simulation::stop < 0) {
        State::tickLast = 1;
    }

    // Report each model
    for(i=0; i < currentStage.size(); i++) {
        currentStage[i]->report();
    }
}
}