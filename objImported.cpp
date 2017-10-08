
#include "ModelImporter.h"

class objImporter : public ModelImporter {

public:

    objImporter() : ModelImporter() {}

    objImporter(std::string filepath) {

    }

    void import(const std::string& filepath) {

        std::ifstream objFile;
        objFile.open(filepath);

        Vec3f vertices;

        // Read file into vertices
        // Need to support storage of polygons instead of just lines...

    }

};
