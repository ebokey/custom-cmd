#include "../../osk/include/block.hpp"
using namespace OSK;

class Model : public Block {

public:

    // Methods
    Model(double x10_, double x20_);
    void initialize();
    void update();
    void report();

    // Members
    double x1;
    double x2;
    double x1d;
    double x2d;

    double x10;
    double x20;
};