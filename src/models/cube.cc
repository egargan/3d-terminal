
#include "../model.h"

class Cube : public Model {

 public:

  explicit Cube(float size) : Model() {
    size /= 2.0;

    // Define model vertices
    vertices_.push_back({-size, -size, -size});
    vertices_.push_back({-size, -size, size});
    vertices_.push_back({-size, size, -size});
    vertices_.push_back({-size, size, size});

    vertices_.push_back({size, -size, -size});
    vertices_.push_back({size, -size, size});
    vertices_.push_back({size, size, -size});
    vertices_.push_back({size, size, size});

    // Define cube shape (using triangles)
    faces_ = {
        0, 1, 3, 0, 2, 3,
        1, 5, 7, 1, 3, 7,
        5, 4, 6, 5, 7, 6,
        4, 0, 2, 4, 6, 2,
        4, 5, 0, 1, 5, 0,
        3, 2, 6, 3, 7, 6
    };

  }

  // Gets IndexedList holding vertices and list of 2-tuples of vertex indices denoting edges
  IndexedList GetLines() const override { // 'override' ensures method is doing so, from a base virtual function
    return {
        vertices_, {
            // 2-tuples of vertices representing edges
            0, 2, 2, 6, 6, 4, 4, 0,
            1, 3, 3, 7, 7, 5, 5, 1,
            0, 1, 2, 3, 4, 5, 6, 7
        }
    };
  };

};