#include<iostream>
#include<limits>

#include "include/simulation.hpp"

// Initialize static members of State
//double OSK::State::time = 0;
//double OSK::State::defaultTimeStep = 0.1;
//double OSK::State::timeStep = 0.1;
//double OSK::State::nextTime = 0.1;

int main() {
    /*
    // Testing out the machine epsilon
    const double EPS = std::numeric_limits<double>::epsilon();

    std::cout << "Machine epsilon is: " << EPS << std::endl;
    */

    // Testing out constructor overloading
    double x = 1;
    double xd = 0.5;

    OSK::State* blankState = new OSK::State();
    OSK::State* popState = new OSK::State(x, xd);

    std::cout << "Blank state location is: " << blankState->state << std::endl;
    std::cout << "Populated state is: " << *popState->state <<std::endl;

    // Print out a static State member
    std::cout << "Current simulation time is: " << OSK::State::time << std::endl;

    // Message to indicate the code is still building properly
    std::cout << "\nThe test code is still building properly!\n" << std::endl;
}