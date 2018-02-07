
#ifndef INC_3DTERMINAL_MODELIMPORTER_H
#define INC_3DTERMINAL_MODELIMPORTER_H

#include "Model.h"

#include <cstdio>
#include <fstream>
#include <unistd.h>

#include <string>
#include <vector>

/**
 * Abstract model importer interface.
 *
 * Describes basic structure any model importer should follow.
 */
class ModelImporter {

protected:

    Model model;

    // '= 0' denotes 'pure virtual' method, making class abstract.
    virtual int import(std::string) = 0;

public:

    Model getModel() const {
        return model;
    }
};


#endif //INC_3DTERMINAL_MODELIMPORTER_H
