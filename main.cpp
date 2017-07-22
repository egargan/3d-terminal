#include "Model.h"
#include "Models/Cube.cpp"
#include "Graphics.h"
#include "World.h"

int main() {

    Graphics gfx;
    World world(gfx);

    Cube cube(0.2);

    world.addObject(cube);

    world.renderObjects();

    gfx.wait();

    return 0;
}