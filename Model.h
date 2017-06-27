
#ifndef INC_3DTERMINAL_MODEL_H
#define INC_3DTERMINAL_MODEL_H

#include <vector>

struct point {

    float x, y, z;

    point operator + (const point& rhs) { return point{x + rhs.x, y + rhs.y, z + rhs.z}; }
    point& operator += (const point& rhs) { 
        *this = *this + rhs;
        return *this;
    }

    point operator * (const point& rhs) { return point{x * rhs.x, y * rhs.y, z * rhs.z}; }
    point& operator *= (const point& rhs) {
        *this = *this * rhs;
        return *this;
    }

};


class Model {

    std::vector<point> vertices;

public:

    Model(std::vector<point>);
    ~Model();

    void translate(float x, float y, float z);
    void rotate(point evector, float rotation);
    void scale(float sf);

private:

    // Location in 'World', probably breaks OOP principles but mucho convenient
    point location;

};


#endif //INC_3DTERMINAL_MODEL_H
