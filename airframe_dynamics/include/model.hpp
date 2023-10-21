#include "../osk/include/block.hpp"
using namespace OSK;

class Model : public Block {

public:
    // Methods
    Model(double gamma_);
    void initialize();
    void update();
    void report();

    // Members
    double gamma0;
    double gamma;
    double gammad;
    double k;
    double a_cmd;
    double gamma_cmd;
    double v;
};