
#include "ModelImporter.h"

class objImporter : public ModelImporter {

public:

    objImporter() : ModelImporter() {

    }

    explicit objImporter(const std::string& filepath) {



    }

    int import(const std::string& path) {

        std::ifstream objFile(path.c_str());

        if (objFile.bad()) {
            return -1;
        }

        if (access )

        Vec3f vertices;

        printf("test");


        // Read file into vertices
        // Need to support storage of polygons instead of just lines...

    }

};
