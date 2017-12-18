
#ifndef INC_3DTERMINAL_MODEL_H
#define INC_3DTERMINAL_MODEL_H

#include "Mat3.h"
#include "Vec3.h"
#include "IndexedList.h"

#include <vector>

class Model {

public:

    explicit Model(std::vector<Vec3f> points) : vertices{std::move(points)}, location{0,0,0} {};

    Model() : location{0,0,0} {};

    ~Model() { vertices.clear(); };


    // Unless overridden, an edge will be drawn between every vertex.
    virtual IndexedList getLines() const {

        std::vector<int> edges;

        for (int i = 0; i < vertices.size(); i++) {
            for (int j = i + 1; j < vertices.size(); j++) {
                edges.push_back(i);
                edges.push_back(j);
            }
        }
        return {vertices, edges};
    };



    // Faces of model will be tuples of vertices, thf. will probs need to rework how vertices are stored
    // For now we just want to render the wireframes
    std::vector<Vec3f> vertices;

    Vec3f location;

};


#endif //INC_3DTERMINAL_MODEL_H
