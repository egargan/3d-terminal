#include "Model.h"
#include "Models/all.h"
#include "Graphics.h"
#include "World.h"
#include "objImporter.cpp"

#include <thread>

int main() {

    Graphics gfx;
    World world(gfx);

    Pyramid pyramid(1.5f, 1.0f);
    Cube cube(1.0f);
//
    objImporter impo("../wt_teapot.obj");
    Model tp = impo.getModel();

    world.addObject(tp);
    //world.addObject(cube);
    //world.addObject(pyramid);

    while(true) {
        world.renderObjects();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        gfx.refresh();
    }

    return 0;
}