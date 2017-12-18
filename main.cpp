#include "Model.h"
#include "Models/all.h"
#include "Graphics.h"
#include "World.h"
#include "objImporter.cpp"

#include <thread>

int main() {

//    Graphics gfx;
//    World world(gfx);

//    Pyramid pyramid(1.5f, 1.0f);
//    Cube cube(1.0f);
//    //world.addObject(pyramid);
//    world.addObject(cube);

    objImporter impo("../wt_teapot.obj");
//
//    while(true) {
//        world.renderObjects();
//        gfx.drawString(std::string("test"), 5, 5);
//        std::this_thread::sleep_for(std::chrono::milliseconds(50));
//        gfx.refresh();
//    }


    return 0;
}