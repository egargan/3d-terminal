
#include "../model.h"

class Pyramid : public Model {

 public:

  Pyramid(const float height, const float baseSize) {
    const float half_base = baseSize / 2.0f;

    // 'Origin' of pyramid at height / 3
    const float mass_centre = height / 3.0f;

    vertices_.push_back({0.0f, (mass_centre * 2.0f), 0.0f}); // Peak
    vertices_.push_back({half_base, -mass_centre, half_base});
    vertices_.push_back({half_base, -mass_centre, -half_base});
    vertices_.push_back({-half_base, -mass_centre, half_base});
    vertices_.push_back({-half_base, -mass_centre, -half_base});
  }

  IndexedList GetLines() const override {
    return {
        vertices_, {
            0, 1, 0, 2, 0, 3, 0, 4,
            1, 2, 1, 3, 2, 4, 3, 4
        }
    };
  }

  IndexedList GetFaces() const override {
    return {
        vertices_, {
            0, 1, 2,
            0, 2, 4,
            0, 3, 4,
            0, 3, 1,
            1, 2, 3,
            2, 4, 3
        }
    };
  }

};