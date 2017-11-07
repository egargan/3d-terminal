
#ifndef INC_3DTERMINAL_MODELIMPORTER_H
#define INC_3DTERMINAL_MODELIMPORTER_H

#include "Model.h"

#include <cstdio>
#include <fstream>
#include <unistd.h>

#include <string>

class ModelImporter {

    int import(const std::string&);

protected:

    Model model;

public:

    ModelImporter();
    ModelImporter(const std::string);

    int importFromPath(const std::string);

    Model getModel() const;

};


#endif //INC_3DTERMINAL_MODELIMPORTER_H
