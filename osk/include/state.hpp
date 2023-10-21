#ifndef STATE
#define STATE

#include<limits>
#include<cmath>

namespace OSK {

// Constants
const double EPS = std::numeric_limits<double>::epsilon(); // Machine epsilon

class State {

public:
    // Methods
    State() {};
    State(double &state, double &derivative); // Need to build constructor to assign state and derivative
    State* duplicateState(double &state, double &derivative); // Create a new instance of the state
    void propogate();
    static void updateClock();

    static bool sample();
    static bool sample(double period, double eventTime = 0);
    //static int sample();


    // Variables
    double* state = NULL;
    double* derivative = NULL;

    static double time; // Simulation time
    static double nextTime; // The boundary of the next integrating time-step, i.e time + timeStep
    static double defaultTimeStep; // The default time-step defined by the Simulation
    static double timeStep; // Current simulation time-step
    static int kpass; // Number of evaluations within a time-step; 0 at time-step boundaries
    static bool ready; // Indicates if the simulation is at a time-step boundary; TRUE if at boundary

    static bool tickFirst;
    static bool tickLast;

    // Members for formulas within time-steps
    double x0, xd0, xd1;

};

}

#endif