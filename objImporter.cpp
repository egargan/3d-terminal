
#include <iostream>
#include "ModelImporter.h"

class objImporter : public ModelImporter {

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
        std::vector<float> floatbuf;

        while (std::getline(obj, strbuf)) {

            // Append EOL char to each line, TODO: find actual EOL char instead of appending it? no luck :s
            strbuf.append("\r");

            switch (strbuf.front()) {

                // For now we're only concerned with vertices and faces
                // Other items, e.g. vertex normals 'vn' might be relevant at some point,
                // but we ignore them for now.

                // Quite bulky use of string vectors for parsing each line of obj file,
                // replace each 'case' below with bespoke iterator splitting if speed becomes issue.

                case '#' : { // .obj comment symbol
                    continue;
                }

                case 'v' : { // vertex

                    for (auto& str : splitstr(strbuf, ' ')) {
                        floatbuf.emplace_back((float) strtod(str.c_str(), nullptr));
                    }
                    // insert into list of vertices
                    obj_vertices.emplace_back(Vec3f{floatbuf[0], floatbuf[1], floatbuf[2]});

                    break;
                }

                case 'f' : { // face

                    // get single face indices from string, will be in form 'v/vt/vn':
                    // vertex/vertex texture coordinate index/vertex normal index
                    for (auto &str : splitstr(strbuf, ' ')) {

                        // isolate v in 'v/vt/vn': adjust if supporting vn and/or vt
                        auto vindex = str.substr(0, str.find_first_of('/'));

                        // just dump into list of ints to be parsed as 3-tuples
                        obj_findices.emplace_back(std::stoi(vindex));
                    }
                }

                default : continue;
            }

            strbuf.clear();
            floatbuf.clear();
        }


        return 1;
    }

    // Splits string 'str' about split char 'delimit', returns list of strings delimited by 'delimit'
    std::vector<std::string> splitstr(const std::string& str, const char& delimit) const {

        std::vector<std::string> words;

        // TODO: '+2' ignores first character, but assumes values are +2 spaces ahead - improve
        auto fiter = str.cbegin() + 2; // cbegin gets const pointer
        decltype(fiter) fbegin; // 'declytype(exp)' gets the type of 'exp', while auto uses type deduction

        while (*fiter != '\r') {

            fbegin = fiter;

            while (*fiter != delimit && *std::next(fiter) != '\r') {
                std::advance(fiter, 1);
            }

            words.emplace_back(std::string(fbegin, fiter));
            std::advance(fiter, 1);
        }

        return words;
    }

};
