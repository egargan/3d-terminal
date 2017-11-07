
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
        Mat3f transform = Mat3f::RotationY(0.05f);

        // Apply *permanent* transformation to model
        for (auto& v : object->vertices) {
            v *= transform;
        }

        // Get vertex values + apply *temporary*, value transformations
        auto lines = object->getLines();
        for (auto& v : lines.vertices) {
            v += {0.0f, 0.05f, 1.6f}; // Push object further into Z / away from viewport
            wsTransformer.TransformVec(v);
        }

        for (auto i = lines.indices.cbegin(), end = lines.indices.cend();
                i != end; std::advance(i, 2)) {

            //auto s = lines.vertices[*i];
            //auto e = lines.vertices[*std::next(i)];
            //std::cout << "(" << s.x << ", " << s.y << ") -> (" << e.x << ", " << e.y << ")\n";

            gfx.drawLine(lines.vertices[*i], lines.vertices[*std::next(i)],
                         0.8); // Shade of line (0 = darkest)
        }

    }
    gfx.wait();
}