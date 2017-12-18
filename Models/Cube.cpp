
#include "../Model.h"

class Cube : public Model {

public:

    explicit Cube(float size) : Model() {
        size /= 2.0;
        vertices.push_back({-size, -size, -size});
        vertices.push_back({-size, -size, size});
        vertices.push_back({-size, size, -size});
        vertices.push_back({-size, size, size});

        vertices.push_back({size, -size, -size});
        vertices.push_back({size, -size, size});
        vertices.push_back({size, size, -size});
        vertices.push_back({size, size, size});
    }

    // 'override' ensures method is doing so, from a base virtual function
    IndexedList getLines() const override {
        return {
                vertices, {
                        // 2-tuples of vertices representing edges
                        0,2,  2,6,  6,4,  4,0,
                        1,3,  3,7,  7,5,  5,1,
                        0,1,  2,3,  4,5,  6,7
                }
        };
    };

};