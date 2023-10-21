#include "../osk/include/simulation.hpp"
#include "include/model.hpp"

int main() {
    double tmax = 2.00;
    double dt = 0.01;

    Model* model = new Model(0.0);

    std::vector<Block*> vObj0;
    vObj0.push_back(model);

    std::vector<std::vector<Block*>> vStage;
    vStage.push_back(vObj0);

    double dts[] = {dt};
    Simulation* sim = new Simulation(dts, tmax, vStage);
    sim->run();
}