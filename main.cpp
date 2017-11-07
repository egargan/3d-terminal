#include "Model.h"
#include "Models/all.h"
#include "Graphics.h"
#include "World.h"

#include <thread>

int main() {

    Graphics gfx;
    World world(gfx);

    Pyramid pyramid(1.5f, 1.0f);
    //Cube cube(1.0f);

    world.addObject(pyramid);

    while(true) {
        world.renderObjects();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}