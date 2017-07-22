
#include "../Model.h"

class Cube : public Model {

public:

    Cube(float size) : Model() {
        vertices.push_back({-size, -size, -size});
        vertices.push_back({-size, -size, size});
        vertices.push_back({-size, size, -size});
        vertices.push_back({-size, size, size});

        vertices.push_back({size, -size, -size});
        vertices.push_back({size, -size, size});
        vertices.push_back({size, size, -size});
        vertices.push_back({size, size, size});
    }

    virtual IndexedLineList getLines() const {
        return {
                vertices, {
                        0,2,  2,6,  6,4,  4,0,
                        1,3,  3,7,  7,5,  5,1,
                        0,1,  2,3,  4,5,  6,7
                }
        };
    };

};