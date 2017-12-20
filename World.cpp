
#include "World.h"

#include <iostream>

World::World(Graphics context) : gfx{context}, wsTransformer(context) {};

World::~World() {
    objects.clear();
};

void World::addObject(Model& object) {
    objects.push_back(&object);
}

void World::renderObjects() {

    for (Model* object : objects) {

        // Make transformations
        Mat3f spin = Mat3f::RotationY(0.05f);
        Mat3f tilt = Mat3f::RotationX(0.3f);

        // Apply *permanent* transformation to model
        for (auto& v : object->vertices) {
            v *= spin;
        }

        // Get vertex values + apply *temporary*, value transformations
        auto lines = object->getFaces();

        for (auto& v : lines.vertices) {
            v *= tilt;
            v += {0.0f, -0.6f, 1.8f}; // Push object further into Z / away from viewport
            wsTransformer.TransformVec(v);
        }

        // Draws model edge-by-edge
//        for (auto i = lines.indices.cbegin(), end = lines.indices.cend();
//                i != end; std::advance(i, 2)) {
//
//            gfx.drawLine(lines.vertices[*i], lines.vertices[*std::next(i)],
//                         0.3); // Shade of line (0 = darkest)

        // Draws model by its list of triangles
        for (auto i = lines.indices.cbegin(), end = lines.indices.cend();
            i != end; std::advance(i, 3)) {

            gfx.drawLine(lines.vertices[*i], lines.vertices[*(i+1)], 0.7);
            gfx.drawLine(lines.vertices[*(i+1)], lines.vertices[*(i+2)], 0.7);
            gfx.drawLine(lines.vertices[*(i+2)], lines.vertices[*i], 0.7);
        }

    }
}