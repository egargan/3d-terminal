
#ifndef INC_3DTERMINAL_MODEL_H
#define INC_3DTERMINAL_MODEL_H

#include "Mat3.h"
#include "Vec3.h"
#include "IndexedList.h"

#include <vector>

class Model {

public:

    explicit Model(std::vector<Vec3f>);
    Model();

    virtual IndexedList getLines() const;

    ~Model();

    // Faces of model will be tuples of vertices, thf. will probs need to rework how vertices are stored
    // For now we just want to render the wireframes
    std::vector<Vec3f> vertices;

    Vec3f location;

};


#endif //INC_3DTERMINAL_MODEL_H