
#ifndef INC_3DTERMINAL_INDEXEDLINELIST_H
#define INC_3DTERMINAL_INDEXEDLINELIST_H

#include <vector>
#include "Vec3.h"

// Convenience structure for holding vertices, and indices referring to them
struct IndexedList {

    std::vector<Vec3f> vertices;

    // List of integers, parsed as list of tuples for representing edges or polygons
    std::vector<int> indices;

};


#endif //INC_3DTERMINAL_INDEXEDLINELIST_H
