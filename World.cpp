
#include "World.h"

World::World(Graphics context) : gfx{context}, wsTransformer(context)
{};

void World::addObject(Model object) {
    objects.push_back(object);
}

void World::renderObjects() {

    for (Model object : objects) {



    }

}