
#include <iostream>
#include <chrono>

using mclock = std::chrono::high_resolution_clock;

// Utility timer class.
// Timing begins on instantiation, and ends with end(), returns time elapsed in microseconds.
struct Timer {
  mclock::time_point begin;

  Timer() {
    begin = mclock::now();
  }

  // Ends timer and return micros elapsed since timer instantiated
  double End() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(mclock::now() - begin).count();
  }
};