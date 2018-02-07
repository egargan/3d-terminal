
#include "World.h"

#include <iostream>

/** Constructor accepting graphics object for drawing transformed 3D models. */
World::World(Graphics context) : gfx{context}, wsTransformer(context) {};

/** Clears vector of objects. */
World::~World() {
    objects.clear();
};

/** Adds -reference- to object to world's list of objects - consider object's lifetime! */
void World::addObject(Model& object) {
    objects.push_back(&object);
}

/** Draws 2D-projected models to screen. */
void World::renderObjects() {

    for (Model* object : objects) {

        // Make transformation matrices
        Mat3f spin = Mat3f::RotationY(0.04f);
        Mat3f tilt = Mat3f::RotationX(0.3f);

        // Apply *permanent* transformation to model
        for (auto& v : object->vertices) {
            v *= spin;
        }

        // Get vertex values + apply *temporary*/value transformations
        auto faces = object->getFaces();

        for (auto& v : faces.vertices) {
            v *= tilt;
            v += {0.0f, -0.4f, 1.6f}; // Push object further into Z / away from viewport
            wsTransformer.TransformVec(v);
        }

        // Draws model by its list of triangles
        for (auto i = faces.indices.cbegin(); i != faces.indices.cend(); std::advance(i, 3)) {

            // Below only draws individual vertices
            gfx.drawPixel(faces.vertices[*i].x, faces.vertices[*i].y, 0.7);
            gfx.drawPixel(faces.vertices[*(i+1)].x, faces.vertices[*(i+1)].y, 0.7);
            gfx.drawPixel(faces.vertices[*(i+2)].x, faces.vertices[*(i+2)].y, 0.7);

            // Uncomment to draw -lines- between vertices
//            gfx.drawLine(faces.vertices[*i], faces.vertices[*std::next(i, 1)], 0.7);
//            gfx.drawLine(faces.vertices[*std::next(i, 1)], faces.vertices[*std::next(i, 2)], 0.7);
//            gfx.drawLine(faces.vertices[*std::next(i, 2)], faces.vertices[*i], 0.7);

        }

    }
}