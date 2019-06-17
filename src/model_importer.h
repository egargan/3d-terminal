
#ifndef INC_3DTERMINAL_MODELIMPORTER_H
#define INC_3DTERMINAL_MODELIMPORTER_H

#include <cstdio>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>

#include "model.h"

// Model importer interface - describes basic structure any model importer should follow.
class ModelImporter {

 public:

  Model GetModel() const {
    return model_;
  }

 protected:

  Model model_;

  // '= 0' denotes 'pure virtual' method, making class abstract.
  virtual int Import(std::string) = 0;

};

#endif //INC_3DTERMINAL_MODELIMPORTER_H
