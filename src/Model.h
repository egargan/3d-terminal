
#ifndef INC_3DTERMINAL_MODEL_H
#define INC_3DTERMINAL_MODEL_H

#include "Mat3.h"
#include "Vec3.h"
#include "IndexedList.h"

#include <vector>

/**
 * Model class header.
 *
 * Contains member vectors storing model's vertices and face polygons.
 * Faces are represented as tuples of indices referring to vertex list.
 */
class Model {

public:

    /** Constructs model with given vertices. */
    explicit Model(std::vector<Vec3f> points) : vertices{std::move(points)}, location{0,0,0} {};

    /** Constructs empty model. */
    Model() : location{0,0,0} {};

    /** Clears model vertex list. */
    ~Model() { vertices.clear(); };


    /** Returns list of edges defining model's shape.
     * Unless overriden, will return a list of edges connecting every single vertex - override me!
     *
     * @return IndexedList object containing model vertices, and list of int 2-tuples representing model edges. */
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

    // todo - if we have faces, create getLines to return the lines that make them up

    /** Returns list of vertices, and 3-tuples of vertex indices representing model made up of triangles. */
    virtual IndexedList getFaces() const {
        return {vertices, faces};
    };

    std::vector<Vec3f> vertices;

    // Stored as actual member, as opposed to model lines, as the model importer needs a target for its output.
    /** List of integers parsed as 3-tuples representing model made up of triangles. */
    std::vector<int> faces;

    /** 3D coordinate representing model's location in the 'world'. */
    Vec3f location;

};


#endif //INC_3DTERMINAL_MODEL_H
