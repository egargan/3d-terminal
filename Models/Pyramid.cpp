#include "../Model.h"

class Pyramid : public Model {

public:

    Pyramid(const float height, const float baseSize) {

        // 'Origin' of pyramid at height / 3

        const float halfBase = baseSize / 2.0f;
        const float massCentre = height / 3.0f;

        vertices.push_back({0.0f, (massCentre * 2.0f), 0.0f}); // Peak
        vertices.push_back({halfBase, -massCentre, halfBase});
        vertices.push_back({halfBase, -massCentre, -halfBase});
        vertices.push_back({-halfBase, -massCentre, halfBase});
        vertices.push_back({-halfBase, -massCentre, -halfBase});
    }

    IndexedList getLines() const override {
        return {
                vertices, {
                        0,1,  0,2,  0,3,  0,4,
                        1,2,  1,3,  2,4,  3,4
                }
        };
    }

    IndexedList getFaces() const override {
        return {
                vertices, {
                        0,1,2,
                        0,2,4,
                        0,3,4,
                        0,3,1,
                        1,2,3,
                        2,4,3
                }
        };
    }

};