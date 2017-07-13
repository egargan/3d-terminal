
#ifndef INC_3DTERMINAL_WORLD_H
#define INC_3DTERMINAL_WORLD_H

#include <vector>

// Would forward declare but CLion doesn't seem to like it
// NO,cannot forward declare objects, only pointers
#include "Model.h"
#include "Graphics.h"
#include "WorldScreenTransformer.h"

// Class representing the space in which models / objects exist
class World {

public:

    World(Graphics);
    ~World();

    void addObject(Model);
    void addObject(Model, Vec3f);

    void renderObjects();

private:

    Graphics gfx;
    std::vector<Model> objects;

    WorldScreenTransformer wsTransformer;

};

#endif //INC_3DTERMINAL_WORLD_H
