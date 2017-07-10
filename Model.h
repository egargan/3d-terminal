
#ifndef INC_3DTERMINAL_MODEL_H
#define INC_3DTERMINAL_MODEL_H

#include "Mat3.h"
#include "Vec3.h"
#include <vector>

class Model {

    std::vector<Vec3f> vertices;

public:

    Model(std::vector<Vec3f>);
    ~Model();

private:


};


#endif //INC_3DTERMINAL_MODEL_H
