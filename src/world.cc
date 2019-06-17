
#include <iostream>

#include "world.h"

// Constructor accepting graphics object for drawing transformed 3D models.
World::World(Graphics context) : graphics_{context}, ws_transformer_(context) {};

// Clears vector of objects
World::~World() {
    objects_.clear();
};

// Adds -reference- to object to world's list of objects - consider object's lifetime!
void World::AddObject(Model &object) {
    objects_.push_back(&object);
}

// Draws 2D-projected models to screen
void World::RenderObjects() {
    for (Model* object : objects_) {
        // Make demo ransformation matrices
        Mat3f spin = Mat3f::RotationY(0.04f);
        Mat3f tilt = Mat3f::RotationX(0.3f);

        // Apply *permanent* transformation to model
        for (auto& v : object->vertices_) {
            v *= spin;
        }

        // Get vertex values + apply *temporary*/value transformations
        auto faces = object->GetFaces();

        for (auto& v : faces.vertices_) {
            v *= tilt;
            v += {0.0f, -0.4f, 2.6f}; // Push object further into Z / away from viewport
            ws_transformer_.TransformVec(v);
        }

        // Draws model by its list of triangles
        for (auto i = faces.indices_.cbegin(); i != faces.indices_.cend(); std::advance(i, 3)) {
            // Below only draws individual vertices
            graphics_.DrawPixel(faces.vertices_[*i].x_, faces.vertices_[*i].y_, 0.7);
            graphics_.DrawPixel(faces.vertices_[*(i + 1)].x_, faces.vertices_[*(i + 1)].y_, 0.7);
            graphics_.DrawPixel(faces.vertices_[*(i + 2)].x_, faces.vertices_[*(i + 2)].y_, 0.7);

            // Uncomment to draw -lines- between vertices
//            gfx.DrawLine(faces.vertices[*i], faces.vertices[*std::next(i, 1)], 0.7);
//            gfx.DrawLine(faces.vertices[*std::next(i, 1)], faces.vertices[*std::next(i, 2)], 0.7);
//            gfx.DrawLine(faces.vertices[*std::next(i, 2)], faces.vertices[*i], 0.7);

        }
    }
}
