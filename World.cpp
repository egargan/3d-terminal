
#include "World.h"
#include "Model.h"

World::World(Graphics context) : gfx{context} {};

void World::addObject(Model object) {
    objects.push_back(object);
}

void World::renderObjects() {

    for (Model object : objects) {

        // transform object vertices
        // draw lines

    }

}