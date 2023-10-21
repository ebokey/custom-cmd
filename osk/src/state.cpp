#include "../include/state.hpp"

namespace OSK {

State::State(double &state, double &derivative) {
    // Assign state and deriviative here
    this->state = &state;
    this->derivative = &derivative;
}

State* State::duplicateState(double &state, double &derivative) {
    return new State(state, derivative);
}

void State::propogate() {
    switch(kpass) {
        case 0:
            x0 = *state;
            xd0 = *derivative;
            *state = x0 + timeStep / 2.0 * xd0;
            break;
        case 1:
            xd1 = *derivative;
            *state = x0 + timeStep * xd1;
            break;
    }
}

void State::updateClock() {
    // Update the current sim time depending on the current pass within the time-step
    if(kpass == 0) {
        time += timeStep / 2;
    }

    if(kpass == 1) {
        time = nextTime;
    }

    // Increment kpass, the pass counter
    kpass++;
    kpass = kpass % 2;

    // If the current sim time is at a time-step boundary, initialize nextTime
    if(kpass == 0) {
        ready = 1;
        nextTime = floor((time + EPS) / defaultTimeStep + 1) * defaultTimeStep;
    }
    else {
        ready = 0;  
    }
}

bool State::sample() {
    // Returns TRUE if it is the start of an integrating time-step

    if(ready) {
        return 1;
    }
    else {
        return 0;
    }
}

bool State::sample(double period, double eventTime) {
    // returns TRUE if it is the beginning of the integrating time-step and the time is an even incrememt of period

    // Maybe I need to write something that steps TO the next sample time if that is closer to the current time than nextTime?

    if(ready) { // Need other conditional
        return 1;
    }
    else {
        return 0;
    }
}

}