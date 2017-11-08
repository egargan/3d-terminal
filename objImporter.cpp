
#include "ModelImporter.h"

class objImporter : public ModelImporter {

public:

    explicit objImporter(const std::string path) {
        import(path);
    }


protected:

    virtual int import(const std::string path) {

        bool runloop = false;

        std::ifstream obj(realpath(path.c_str(), nullptr));
        std::vector<Vec3f> objvertices;

        printf("%d\n", obj.is_open());

        if (runloop && obj.is_open() ) {

            while (std::getline(obj, strbuf)) {

                //printf("%s\n", strbuf.c_str());

                // strbuf buffers file line by line
                // read v's and f's

                strbuf.erase();
            }

        }

        // Read file into vertices
        // Need to support storage of polygons instead of just lines...

        return 1;
    }

};
