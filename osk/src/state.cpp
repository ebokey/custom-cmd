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
        double blah0 = time + EPS;
        double blah1 = blah0 / defaultTimeStep;
        double blah2 = blah1 + 1;
        int blah3 = floor(blah2);
        nextTime = blah3 * defaultTimeStep;
        //nextTime = floor((time + EPS) / defaultTimeStep + 1) * defaultTimeStep;
    }
    else {
        ready = 0;  
    }
}

/*
Sample function (Overload #1)
    Determines if the simulation is at the start of an integrating time-step
    TRUE if it is the start of an integrating time-step
    FALSE if it is not at the start of an integrating time-step (e.g. it is within a time-step)
*/
bool State::sample() {
    if(ready) {
        return 1;
    }
    else {
        return 0;
    }
}

/*
Sample function (Overload #2)
    Returns TRUE if BOTH of the following conditions are met:
    (1) Time is at the beginning of an integrating time-step
    (2) Time is an even increment of the input period
*/
bool State::sample(double period, double eventTime) {
    // Maybe I need to write something that steps TO the next sample time if that is closer to the current time than nextTime?
    // UPDATE: I don't think this is the case, can't predict this function call

    // NOTE: this function seems to skip some sample points here and there, FIX IT!

    double blah = floor((time + EPS) / period) * period;

    bool isIncrement = blah == time;

    if(ready && isIncrement) { // Need other conditional
        return 1;
    }
    else {
        return 0;
    }
}

}