
#ifndef INC_3DTERMINAL_MODEL_H
#define INC_3DTERMINAL_MODEL_H

#include <vector>

struct point {
    float x, y, z;
};


class Model {

    std::vector<point> vertices;

public:

    Model(std::vector<point>);
    ~Model();

    void translate(float x, float y, float z);
    void rotate(point evector, float rotation);

};


#endif //INC_3DTERMINAL_MODEL_H
