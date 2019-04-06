
#include <iostream>
#include <fstream>

#include "ModelImporter.h"

/**
 * Model importer for .OBJ files.
 *
 * .OBJ files are perhaps the simplest object description file, holding a list of vertices, as well as lists of indices
 * that reference those vertices to describe faces.
 *
 * .OBJ stores other data e.g. vertex normals, texture data,
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

        std::ifstream obj(realpath(path.c_str(), NULL), std::ifstream::in);

        assert(obj.is_open());

        std::vector<Vec3f> obj_vertices;
        std::vector<int> obj_findices;

        // Buffers for parse's temporary storage
        std::string strbuf;
        std::vector<std::string> itembuf;

        // Insert dummy vertex as .obj vertex indices are 1-based, and World::renderObjects() iterates from 0
        obj_vertices.push_back(Vec3f{0,0,0});

        while (std::getline(obj, strbuf)) {

            // Break early if comment line
            if (strbuf.empty() || strbuf.front() == '#') continue;

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
                            strtof(itembuf[1].c_str(), nullptr),
                            strtof(itembuf[2].c_str(), nullptr),
                            strtof(itembuf[3].c_str(), nullptr)
                    });
                    break;
                }

                case objData::f : { // face

                    // Collect vertex indices making up faces
                    // Some .objs use > 3 vertex indices in face declarations, for squares, pentagons, etc,
                    // we break down these shapes into component triangles, e.g.
                    //
                    //  2 - 3
                    //  | / |  -> (1,2,3), (1,3,4)
                    //  1 - 4
                    //
                    for (int i = 2; i < itembuf.size() - 1; i++) {
                        // Isolate v in 'v/vt/vn': adjust if supporting vn and/or vt
                        obj_findices.push_back(std::stoi(itembuf[1].substr(0, itembuf[1].find_first_of('/'))));
                        obj_findices.push_back(std::stoi(itembuf[i].substr(0, itembuf[i].find_first_of('/'))));
                        obj_findices.push_back(std::stoi(itembuf[i+1].substr(0, itembuf[i+1].find_first_of('/'))));
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
        const auto& fend = str.cend();
        decltype(fiter) fbegin; // 'decltype(exp)' gets the type of 'exp', while 'auto' uses type deduction

        // 'fend + 1' since strings are constructed [begin, end), so we advance beyond cend
        for (; fiter != fend + 1; std::advance(fiter, 1)) {

            // Skip over additional delimit chars
            while (*fiter == delimit) {
                std::advance(fiter, 1);
            }

            // True if trailing delimiters
            if (fiter == fend) break;

            // Begin word demarcation
            fbegin = fiter;

            while (*fiter != delimit && fiter != fend) {
                std::advance(fiter, 1);
            }

            words.emplace_back(std::string(fbegin, fiter));
        };

        return words;
    }

};
