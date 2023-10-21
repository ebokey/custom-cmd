#include "../../osk/include/block.hpp"
using namespace OSK;

class Target : public Block {

public:
    Target(double x, double y, double vx, double vy);
    void report();

    double x, y, vx, vy;
};