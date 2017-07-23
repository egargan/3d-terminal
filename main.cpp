#include "Model.h"
#include "Models/Cube.cpp"
#include "Graphics.h"
#include "World.h"

#include <thread>

int main() {

    Graphics gfx;
    World world(gfx);

    Cube cube(1.0);

    world.addObject(cube);

    gfx.wait();

    while(true) {
        world.renderObjects();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}