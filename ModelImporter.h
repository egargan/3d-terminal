
#ifndef INC_3DTERMINAL_MODELIMPORTER_H
#define INC_3DTERMINAL_MODELIMPORTER_H

#include "Model.h"

#include <cstdio>
#include <fstream>
#include <unistd.h>

#include <string>
#include <vector>

class ModelImporter {

protected:

    Model model;
    virtual int import(std::string) = 0;

public:

    ModelImporter() = default;

    Model getModel() const {
        return model;
    }
};


#endif //INC_3DTERMINAL_MODELIMPORTER_H
