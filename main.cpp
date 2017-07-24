#include "Model.h"
#include "Models/Cube.cpp"
#include "Graphics.h"
#include "World.h"

#include <thread>

int main() {

    Graphics gfx;
    World world(gfx);

    Cube cube(0.2f);

    world.addObject(cube);

    while(true) {
        world.renderObjects();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}