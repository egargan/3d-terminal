#include <iostream>
#include <chrono>

/**
 * Utility timer class.
 *
 * Timing begins on instantiation, and ends with end().
 * end() returns time elapsed in microseconds.
 */

using mclock = std::chrono::high_resolution_clock;

struct timer {

    mclock::time_point begin;

    timer() {

        begin = mclock::now();
    }

    /** Ends timer and return micros elapsed since timer instantiated. */
    double end() const {

        return std::chrono::duration_cast<std::chrono::microseconds>(mclock::now() - begin).count();
    }

};