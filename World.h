
#ifndef INC_3DTERMINAL_WORLD_H
#define INC_3DTERMINAL_WORLD_H

#include <vector>

// Would forward declare but CLion doesn't seem to like it
#include "Model.h"
#include "Graphics.h"

// Class representing the space in which models / objects exist
class World {

public:

    World(Graphics);
    ~World();

    void addObject(Model);
    void addObject(Model, point);

    void renderObjects();

private:

    Graphics gfx;
    std::vector<Model> objects;

};

#endif //INC_3DTERMINAL_WORLD_H
