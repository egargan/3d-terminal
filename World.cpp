
#include "World.h"

World::World(Graphics context) : gfx{context}, wsTransformer(context) {};

World::~World() {
    objects.clear();
};

void World::addObject(Model& object) {
    objects.push_back(&object);
}

void World::renderObjects() {

    for (Model* object : objects) {

        auto lines = object->getLines();

        for ( auto& v : lines.vertices) {
            wsTransformer.TransformVec(v);
        }

        for (auto i = lines.indices.cbegin(), end = lines.indices.cend();
                i != end; std::advance(i,2)) {
            auto s = lines.vertices[*i];
            auto e = lines.vertices[*std::next(i)];
            //printf("(%d,%d) -> (%d,%d)\n", (int)s.x, (int)s.y, (int)e.x, (int)e.y);
            gfx.drawLine(lines.vertices[*i], lines.vertices[*std::next(i)], 0.1);
        }

    }

}