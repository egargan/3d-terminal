#include <iostream>

class timer {

    std::clock_t start_time;

public:

    timer() {

        double duration;

        start_time = std::clock();

    }

    double end() const {

        return ( std::clock() - start_time ) / (double) CLOCKS_PER_SEC;

    }
};