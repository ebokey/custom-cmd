#include "../osk/include/simulation.hpp"
#include "include/target.hpp"

int main() {
    double tmax = 10.0;
    double dt = 0.01;

    Target* target = new Target(20.0, 5.0, -1.0, 0.0);

    std::vector<Block*> vObj0;
    vObj0.push_back(target);

    std::vector<std::vector<Block*>> vStage;
    vStage.push_back(vObj0);

    double dts[] = {dt};
    Simulation* sim = new Simulation(dts, tmax, vStage);
    sim->run();
}