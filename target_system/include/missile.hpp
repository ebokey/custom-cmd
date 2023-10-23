#include "../../osk/include/simulation.hpp"
#include "target.hpp"
using namespace OSK;

class Missile : public Block {

public:
    Missile(Target* target, double x, double y, double vel);
    void update();
    void report();

    double x, y, vx, vy, vel, d;
    Target* target;
};