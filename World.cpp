
#include "World.h"

#include <cstdio>
#include <iostream>

World::World(Graphics context) : gfx{context}, wsTransformer(context) {};

World::~World() {
    objects.clear();
};

void World::addObject(Model& object) {
    objects.push_back(&object);
}

void World::renderObjects() {

    gfx.clear();

    for (Model* object : objects) {

        // Make transformation matrix
        Mat3f transform;
        transform = Mat3f::RotationX(0.1f);
        transform *= Mat3f::RotationY(0.1f);

        // Do some world-space transformations
        for ( auto& v : object->vertices) {
            v *= transform;
        }

        auto lines = object->getLines();

        // Get screen-space coordinates and display
        for (auto i = lines.indices.cbegin(), end = lines.indices.cend();
                i != end; std::advance(i,2)) {

            //auto s = lines.vertices[*i];
            //auto e = lines.vertices[*std::next(i)];
            //std::cout << "(" << s.x << ", " << s.y << ") -> (" << e.x << ", " << e.y << ")\n";

            gfx.drawLine(wsTransformer.getTransformedVec(lines.vertices[*i]),
                         wsTransformer.getTransformedVec(lines.vertices[*std::next(i)]),
                         0.5); // Shade of line (0 = darkest)
        }

    }
    gfx.wait();
}