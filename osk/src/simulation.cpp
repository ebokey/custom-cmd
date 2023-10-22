#include "../include/simulation.hpp"

namespace OSK {

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

Simulation::Simulation(double* timeSteps, double maxTime, std::vector<std::vector<Block*>> &stages) {
    // Constructor goes here
    this->timeSteps = timeSteps;
    this->maxTime = maxTime;
    this->stages = stages;
}

void Simulation::run() {
    // Need to fully flesh out how to handle multiple sim stages
    for(int i=0; i < stages.size(); i++) {

        // Extract the current model stage and timeStep
        std::vector<Block*> currentStage = stages[i];
        double timeStep = timeSteps[i];

        // Set the static variables
        // State::time should not need to change
        State::defaultTimeStep = timeStep;
        State::timeStep = timeStep;
        State::nextTime = State::time + timeStep;
        State::ready = 1;
        //State::tickFirst = 1;

        // Initialize each model
        int j;
        int numModels = currentStage.size();
        for(j=0; j < numModels; j++) {
            currentStage[j]->initialize();

            // Report the model
            currentStage[j]->report();
        }

        // Put a loop here - need to add the rest of the conditions
        while(State::time < maxTime) {
            // Update each model
            for(j=0; j < numModels; j++) {
                currentStage[j]->update();

                // Propogate the states
                for(int k=0; k <currentStage[j]->states.size(); k++) {
                    currentStage[j]->states[k]->propogate();
                }

                // Update clock
                State::updateClock();
            }

            // Report each model
            for(j=0; j < numModels; j++) {
                currentStage[j]->report();
            }

            //State::tickFirst = 0;
        }
    }
}

}