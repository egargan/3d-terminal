
#ifndef INC_3DTERMINAL_WORLD_H
#define INC_3DTERMINAL_WORLD_H

#include <vector>

#include "Model.h"
#include "Graphics.h"
#include "WorldScreenTransformer.h"

/**
 * Header of 'World' class.
 *
 * Represents the space in which models / objects exist.
 */
class World {

public:

    World(Graphics);
    ~World();

    void addObject(Model&);

    void renderObjects();

private:

    Graphics gfx;
    std::vector<Model*> objects;

    /** Object that handles projection of 3D objects to 2D space. */
    WorldScreenTransformer wsTransformer;

};

#endif //INC_3DTERMINAL_WORLD_H
