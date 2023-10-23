#include "../../osk/include/simulation.hpp"
#include "target.hpp"
using namespace OSK;

class Radar : public Block {

public:
    Radar(Target* target, double theta, double wn, double zeta);
    void update();
    void report();

    double x1, x1d, x2, x2d, theta_err, wn, zeta;
    Target* target;
};