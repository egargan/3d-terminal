#include "Model.h"

Model::Model(std::vector<point> points) : vertices{points}, location{0,0,0} {



};

Model::~Model() { vertices.clear(); };

void Model::translate(float x, float y, float z) {

    for (point vertex : vertices)
        vertex += {x,y,z};

}

void Model::rotate(point evector, float rotation) {

    // hmm

}

void Model::scale(float sf) {

    for (point vertex : vertices)
        vertex *= point{sf,sf,sf};

}