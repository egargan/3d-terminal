
#ifndef INC_3DTERMINAL_INDEXEDLINELIST_H
#define INC_3DTERMINAL_INDEXEDLINELIST_H

#include <vector>
#include "Vec3.h"


struct IndexedList {

    std::vector<Vec3f> vertices;
    std::vector<int> indices;

};


#endif //INC_3DTERMINAL_INDEXEDLINELIST_H
