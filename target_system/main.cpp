#include "../osk/include/simulation.hpp"
#include "include/missile.hpp"
#include "include/radar.hpp"

int main() {
    double tmax = 40.0;
    double dt = 0.01;

    Target* target = new Target(20.0, 5.0, -1.0, 0.0);
    Missile* missile = new Missile(target, 0.0, 0.0, 2.0);
    Radar* radar = new Radar(target, 60.0, 2.643, 0.7);

    std::vector<Block*> vObj0;
    vObj0.push_back(target);
    //vObj0.push_back(missile);
    vObj0.push_back(radar);

    std::vector<Block*> vObj1;
    vObj1.push_back(target);
    vObj1.push_back(missile);
    vObj1.push_back(radar);

    std::vector<std::vector<Block*>> vStage;
    vStage.push_back(vObj0);
    vStage.push_back(vObj1);

    double dts[] = {dt,dt};
    Simulation* sim = new Simulation(dts, tmax, vStage);
    sim->run();
}