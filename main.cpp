#include "Model.h"
#include "Models/all.h"
#include "Graphics.h"
#include "World.h"
#include "objImporter.cpp"

#include <thread>

/**
 * Main program procedure.
 *
 * Declares any models, adds them to a 'world' object, and performs render loop.
 */
int main() {

    // Declare new graphics context and 'world' object
    Graphics gfx;
    World world(gfx);

    // Declare some models to be added to world.
    //Pyramid pyramid(1.5f, 1.0f);
    //Cube cube(1.0f);

    // Create model from .obj file
    objImporter impo("../Models/aa.obj");
    Model tp = impo.getModel();

    // Add defined objects to world
    world.addObject(tp);

    // Render loop - been meaning to move to own class where it would make more sense.
    while(true) {

        world.renderObjects();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        gfx.refresh();
    }

    return 0;
}