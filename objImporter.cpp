
#include <iostream>
#include "ModelImporter.h"

/**
 * Model importer for .OBJ files.
 *
 * .OBJ files are perhaps the simplest object description file, holding a list of vertices, as well as lists of indices
 * that reference those vertices to describe faces.
 *
 * It of course stores other data e.g. vertex normals, texture data,
 * etc., but this is currently irrelevant to this project as we're only looking to render wireframes.
 */
class objImporter : public ModelImporter {

    /** Enum for distinguishing data in obj file. */
    // Is not exhaustive! Only includes elements relevant to current modeller
    enum objData {
        hash,       // comment
        v,          // vertex
        vn,         // vertex normal
        f,          // face
        unrecognised,
    };

    /** Returns locally-defined enum based on .obj's data indicators, e.g. 'v', 'f' etc.
     *
     * @param el Data indicator string. */
    objData mapObjElement(const std::string& el) const {

        if (el == "v") return objData::v;
        if (el == "vn") return objData::vn;
        if (el == "f") return objData::f;
        if (el == "#") return objData::hash;

        return unrecognised;
    }

public:

    /** Constructor accepting path to .obj file, relative to project base directory. */
    explicit objImporter(const std::string& path) {
        import(path);
    }


protected:

    /** Performs import operation on .obj file at given path.
     *
     * Iterates through the .obj file and populates a series of vectors holding vertices and faces. */
    virtual int import(const std::string path) override {

        std::ifstream obj(realpath(path.c_str(), nullptr));

        assert(obj.is_open());

        std::vector<Vec3f> obj_vertices;
        std::vector<int> obj_findices;

        // Buffers for parse's temporary storage
        std::string strbuf;
        std::vector<std::string> itembuf;

        // Insert dummy vertex as .obj vertex indices are 1-based, and World::renderObjects() iterates from 0
        obj_vertices.push_back(Vec3f{0,0,0});

        while (std::getline(obj, strbuf)) {

            itembuf = splitstr(strbuf, ' ');

            // Switch on first string in line, indicating what data follows, e.g. 'v', 'f'
            // Can't switch on strings so have to use enum
            switch (mapObjElement(itembuf.front())) {

                // For now we're only concerned with vertices and faces

                // Quite bulky use of string vectors for parsing each line of obj file,
                // replace each 'case' below with bespoke iterator splitting if speed becomes issue.

                case objData::v : { // vertex

                    // Parse next three items in itembuf - expected to be float values x, y, z
                    obj_vertices.emplace_back(Vec3f{
                            (float) strtod(itembuf[1].c_str(), nullptr),
                            (float) strtod(itembuf[2].c_str(), nullptr),
                            (float) strtod(itembuf[3].c_str(), nullptr)
                    });
                    break;
                }

                case objData::f : { // face

                    // Get single face indices from string, will be in form 'v/vt/vn':
                    // vertex/vertex texture coordinate index/vertex normal index
                    for (int i = 1; i <= 3; i++) {

                        // Isolate v in 'v/vt/vn': adjust if supporting vn and/or vt
                        auto vindex = itembuf[i].substr(0, itembuf[i].find_first_of('/'));

                        // Just dump into list of ints to be parsed as 3-tuples
                        obj_findices.push_back(std::stoi(vindex));
                    }
                    break;
                }

                default : continue;
            }

            // Clear per-line buffers
            strbuf.clear();
            itembuf.clear();
        }

        model.vertices = obj_vertices;
        model.faces = obj_findices;

        return 1;
    }

    /** Splits string 'str' about split char 'delimit', returns list of strings delimited by 'delimit'. */
    std::vector<std::string> splitstr(const std::string& str, const char& delimit) const {

        std::vector<std::string> words;

        auto fiter = str.cbegin(); // cbegin gets const pointer
        decltype(fiter) fbegin; // 'decltype(exp)' gets the type of 'exp', while 'auto' uses type deduction

        while (*fiter != '\0') {

            fbegin = fiter;

            while (*fiter != delimit && *std::next(fiter) != '\0') {
                std::advance(fiter, 1);
            }

            words.emplace_back(std::string(fbegin, fiter));
            std::advance(fiter, 1);
        }

        return words;
    }

};
