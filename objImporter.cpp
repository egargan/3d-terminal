
#include <iostream>
#include "ModelImporter.h"

#include <ctime>

class objImporter : public ModelImporter {

    // Enum for distinguishing data in obj file
    // Is not exhaustive! Only includes elements relevant to current modeller
    enum objData {
        hash,       // comment
        v,          // vertex
        vn,         // vertex normal
        f,          // face
        unrecognised,
    };

    // Outputs one of above enums based on
    objData mapObjElement(const std::string& el) const {

        if (el == "v") return objData::v;
        if (el == "vn") return objData::vn;
        if (el == "f") return objData::f;
        if (el == "#") return objData::hash;
        return unrecognised;
    }

public:

    explicit objImporter(const std::string path) {
        import(path);
    }


protected:

    virtual int import(const std::string path) {

        std::ifstream obj(realpath(path.c_str(), nullptr));
        assert(obj.is_open());

        std::vector<Vec3f> obj_vertices;
        std::vector<int> obj_findices;

        // Buffers for parse's temporary storage
        std::string strbuf;
        std::vector<std::string> itembuf;

        int linenum = 0;

        std::clock_t start;
        double duration;
        start = std::clock();

        while (std::getline(obj, strbuf)) {

            linenum++;

            itembuf = splitstr(strbuf, ' ');

            switch (mapObjElement(itembuf.front())) {

                // For now we're only concerned with vertices and faces
                // Other items, e.g. vertex normals 'vn' might be relevant at some point,
                // but we ignore them for now.

                // Quite bulky use of string vectors for parsing each line of obj file,
                // replace each 'case' below with bespoke iterator splitting if speed becomes issue.

                case objData::hash : { // .obj comment symbol
                    continue;
                }

                case objData::v : { // vertex

                    // Parse next three items in itembuf - expected to be float values x, y, z
                    obj_vertices.emplace_back(Vec3f{
                            (float) strtod(itembuf[1].c_str(), nullptr),
                            (float) strtod(itembuf[2].c_str(), nullptr),
                            (float) strtod(itembuf[3].c_str(), nullptr)
                    });

//                    printf("%f, %f, %f\n",(float) strtod(itembuf[1].c_str(), nullptr),
//                           (float) strtod(itembuf[2].c_str(), nullptr),
//                                   (float) strtod(itembuf[3].c_str(), nullptr));

                    break;
                }

                case objData::f : { // face

                    // get single face indices from string, will be in form 'v/vt/vn':
                    // vertex/vertex texture coordinate index/vertex normal index
                    for (int i = 1; i <= 3; i++) {

                        // isolate v in 'v/vt/vn': adjust if supporting vn and/or vt
                        auto vindex = itembuf[1].substr(0, itembuf[1].find_first_of('/'));

                        // just dump into list of ints to be parsed as 3-tuples
                        obj_findices.emplace_back(std::stoi(vindex));
                    }

                    break;
                }

                default : continue;
            }

            strbuf.clear();
            itembuf.clear();
        }

        model.vertices = obj_vertices;
        model.faces = obj_findices;

        duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

        //std::cout << duration << "\n";

        return 1;
    }

    // Splits string 'str' about split char 'delimit', returns list of strings delimited by 'delimit'
    std::vector<std::string> splitstr(const std::string& str, const char& delimit) const {

        std::vector<std::string> words;

        auto fiter = str.cbegin(); // cbegin gets const pointer
        decltype(fiter) fbegin; // 'declytype(exp)' gets the type of 'exp', while auto uses type deduction

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
