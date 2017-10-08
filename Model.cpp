#include "Model.h"

Model::Model(std::vector<Vec3f> points) : vertices{points}, location{0,0,0} { };

Model::Model() : location{0,0,0} {};

// Unless overridden, an edge will be drawn between every vertex.
IndexedList Model::getLines() const {

    std::vector<int> edges;

    for (int i = 0; i < vertices.size(); i++) {
        for (int j = i + 1; j < vertices.size(); j++) {
            edges.push_back(i);
            edges.push_back(j);
        }
    }
    return {vertices, edges};
};

Model::~Model() { vertices.clear(); };